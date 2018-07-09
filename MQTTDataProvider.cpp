#include <cstdio>

#include "mbed.h"
#include "rtos.h"
#undef MBED_CONF_APP_ESP8266_DEBUG
#include "easy-connect.h"
#include "EthernetInterface.h"
#include "MQTTThreadedClient.h"
#include "mbedtls/platform.h"
#include "m2mresource.h"

using namespace MQTT;


//#define AMAZON_CERT
#define MBED_CLOUD_CERT

#ifdef MBED_CLOUD_CERT
       #include "mbed_cloud_dev_credentials.c"
       bool isDER = true;
       static const char * clientID = "mbed-sample"; 
       static const char * topic_1 = "topic/test";
       const char* hostname = "ingest.mqtt.data.mbedcloudintegration.net";
#elif defined(AMAZON_CERT)
  bool isDER = false;
  #include "amazon_mqtt_conf_new.h"   // TLS handshake issue??
  //#include "amazon_mqtt_conf.h"
#elif defined(LOCAL_CERT)
      #include "local_mqtt_conf.h"
      bool isDER=false;
#endif

int arrivedcount = 0;

#include "MQTTDataProvider.h"

long epochtime = 1528406876;   // Thursday, June 7, 2018 9:27:56 PM
static const float sample_values[62] =
      {
        0.0,
        0.09983341664682815,
        0.19866933079506122,
        0.2955202066613396,
        0.3894183423086505,
        0.479425538604203,
        0.5646424733950355,
        0.6442176872376911,
        0.7173560908995228,
        0.7833269096274833,
        0.8414709848078965,
        0.8912073600614354,
        0.9320390859672264,
        0.963558185417193,
        0.9854497299884603,
        0.9974949866040544,
        0.9995736030415051,
        0.9916648104524686,
        0.9738476308781951,
        0.9463000876874145,
        0.9092974268256817,
        0.8632093666488738,
        0.8084964038195901,
        0.74570521217672,
        0.6754631805511506,
        0.5984721441039564,
        0.5155013718214642,
        0.4273798802338298,
        0.33498815015590466,
        0.23924932921398198,
        0.1411200080598672,
        0.04158066243329049,
        -0.058374143427580086,
        -0.15774569414324865,
        -0.25554110202683167,
        -0.35078322768961984,
        -0.44252044329485246,
        -0.5298361409084934,
        -0.6118578909427193,
        -0.6877661591839741,
        -0.7568024953079282,
        -0.8182771110644108,
        -0.8715757724135881,
        -0.9161659367494549,
        -0.9516020738895161,
        -0.977530117665097,
        -0.9936910036334645,
        -0.9999232575641008,
        -0.9961646088358406,
        -0.9824526126243325,
        -0.9589242746631385,
        -0.9258146823277321,
        -0.8834546557201531,
        -0.8322674422239008,
        -0.7727644875559871,
        -0.7055403255703919,
        -0.6312666378723208,
        -0.5506855425976376,
        -0.4646021794137566,
        -0.373876664830236,
        -0.27941549819892586,
        -0.13216250427209502
 };

void messageArrived(MessageData& md)
{
    Message &message = md.message;
    printf("Arrived Callback 1 : qos %d, retained %d, dup %d, packetid %d\r\n", message.qos, message.retained, message.dup, message.id);
    printf("Payload [%.*s]\r\n", message.payloadlen, (char*)message.payload);
    ++arrivedcount;
}

string MQTTDataProvider::getDataOld(int i){
     //returns JSON in format which was used in 1st demo with plottting
     if (i == sizeof(sample_values) / sizeof(sample_values[0])) {
                i = 0;
      }

     char BUFFER[MAX_MQTT_PAYLOAD_SIZE];
     sprintf(BUFFER, "{\"DeviceID\":\"53791ab8k93e000000000001001003sf\",\"Resource\":\"phase\",\"Value\":%.3f,\"TimeStamp\":%ld}", sample_values[i], epochtime);

     string json = BUFFER;
     return json;
}    

string MQTTDataProvider::getData(int i){

    //returns JSON as described here: https://confluence.arm.com/display/IoTBU/Message+Structure
    char str_time[32];
    sprintf(str_time, "%ld", epochtime);

    string json="{\"f\": 1,";                        
    json += "\"id\": \"";                                 
    json += deviceId;                                   
    json += "\",";
    json += "\"d\": [";                                
    
    size_t j=0; // resource counter - it is used to print or not to print the comma after }
    for( std::map<string,M2MResource*>::const_iterator it = resources.begin(); it != resources.end(); ++it )
    {
         //printf ("%d=>  str_resource key=%s  value=%s \r\n",j,(it->first).c_str(), (it->second)->get_value_string().c_str());
         if (i == sizeof(sample_values) / sizeof(sample_values[0])) {
                i = 0;
         }
         
         //this code leads to memory corruption later on - some issue with update_value()
         /* 
         char BUFFER[32];
         sprintf(BUFFER, "%.3f", sample_values[i]);
         //(it->second)->update_value((unsigned char*)BUFFER, strlen(BUFFER));   // this line leads to memory corruption later on
          const char *s="my value 1";
          (it->second)->update_value((unsigned char*)s, strlen(s));
         printf("i=%d value=-%s- \r\n", i, (it->second)->get_value_string().c_str());
         return "POINT 3";//TODO remove it
          */

         j++;
         json += "{";
         json += "\"";
         json += it->first;   //resource_path
         json += "\": [";
             json += "{";
             json += "\"t\": ";
             json +=str_time;
             json += ",";

             json += "\"v\": {";
             
             json += "\"";
             json += (it->second)->resource_type();   
             json += "\":";
             json += "299";   //value
             //json += (it->second)->get_value_string().c_str(); //value;
             json += "}";
         json += "}";
         json += "]";

         json += "}";
         if (resources.size() > j) json += ",";
         json += "";
         
    }

    json += "]}";
     
    printf(" ===> END getData() counter=%d \r\n", i);
    return json;
}    

void MQTTDataProvider::run(){

    Thread msgSender(osPriorityNormal); // there are optional args: stack_size, etc

    //NetworkInterface* network = easy_connect(true); //use if no Mbed Cloud Client
     NetworkInterface* network = easy_get_netif(true); // already created by Mbed Cloud Client
    // do not create new connection, because it will raise the error:  
    // error NSAPI_ERROR_IS_CONNECTED  -3015 socket is already connected (error code is defined in nsapi_types.h)
    if (!network) {
        mbedtls_printf("===ERROR=== easy_get_netif inside MQTTDataProvider::run \r\n");
        return ;
    }

    int port = 8883;

#ifdef MBED_CLOUD_CERT
      // DER format
      MQTTThreadedClient mqtt(network, (const unsigned char*)(MBED_CLOUD_DEV_LWM2M_SERVER_ROOT_CA_CERTIFICATE), (const unsigned char*)MBED_CLOUD_DEV_BOOTSTRAP_DEVICE_CERTIFICATE, (const unsigned char*)MBED_CLOUD_DEV_BOOTSTRAP_DEVICE_PRIVATE_KEY, isDER);

      mqtt.ssl_ca_len          = sizeof(MBED_CLOUD_DEV_BOOTSTRAP_SERVER_ROOT_CA_CERTIFICATE);
      mqtt.ssl_client_cert_len = sizeof(MBED_CLOUD_DEV_BOOTSTRAP_DEVICE_CERTIFICATE);
      mqtt.ssl_client_pkey_len = sizeof(MBED_CLOUD_DEV_BOOTSTRAP_DEVICE_PRIVATE_KEY);

#else  
      // PEM format
      MQTTThreadedClient mqtt(network, (const unsigned char*)TLS_CA_PEM, (const unsigned char*)TLS_CLIENT_CERT, (const unsigned char*)TLS_CLIENT_PKEY, isDER);
#endif 

    MQTTPacket_connectData logindata = MQTTPacket_connectData_initializer;
    logindata.MQTTVersion = 3;


    logindata.clientID.cstring = (char *)  clientID;

    mqtt.setConnectionParameters(hostname, port, logindata);
    mqtt.addTopicHandler(topic_1, messageArrived);

    msgSender.start(mbed::callback(&mqtt, &MQTTThreadedClient::startListener));
 

    int i=0;
    while(true)
    {
         Thread::wait(1000);
         PubMessage message;
         message.qos = QOS0;
         message.id = 123;
        
         // if (i > 3) continue;  // This is temporary statement to concentrate on TLS handshake issue
                  
         strcpy(&message.topic[0], topic_1);
         

         string json=getData(i);  //temporary commented to concentrate on TLS handshake issue 
         // string json=getDataOld(i); //old JSON format 
         //string json="X";  // just a placeholder

         if  (json.length() >= MAX_MQTT_PAYLOAD_SIZE){
            printf("ERROR json lengh > %d  \r\n", MAX_MQTT_PAYLOAD_SIZE);
            break;
         }
 
         sprintf(&message.payload[0], "%s", json.c_str());
         epochtime++; // TODO  use system time call here

         message.payloadlen = strlen((const char *) &message.payload[0]);
         printf("i=%d  topic=%s payload=%s \r\n", i,  &message.topic[0],   &message.payload[0] );
         int ret = mqtt.publish(message);
         if (ret) printf("ERROR mqtt.publish() ret=%d  ", ret);
         if (ret) Thread::wait(6000);
        
         i++;
     }

} 
