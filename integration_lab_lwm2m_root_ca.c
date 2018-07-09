/*
 * Copyright (c) 2018 ARM Limited. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

const uint8_t MBED_CLOUD_DEV_LWM2M_SERVER_ROOT_CA_CERTIFICATE[] = 
{ 0x30, 0x82, 0x02, 0x30, 0x30, 0x82, 0x01, 0xd5,
0xa0, 0x03, 0x02, 0x01, 0x02, 0x02, 0x10, 0x26,
0xf9, 0x08, 0xfc, 0xf1, 0xc0, 0x46, 0xa4, 0x4a,
0x4d, 0x2c, 0xf1, 0x94, 0x27, 0xf9, 0x1f, 0x30,
0x0a, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d,
0x04, 0x03, 0x02, 0x30, 0x6f, 0x31, 0x0b, 0x30,
0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02,
0x47, 0x42, 0x31, 0x17, 0x30, 0x15, 0x06, 0x03,
0x55, 0x04, 0x08, 0x13, 0x0e, 0x43, 0x61, 0x6d,
0x62, 0x72, 0x69, 0x64, 0x67, 0x65, 0x73, 0x68,
0x69, 0x72, 0x65, 0x31, 0x12, 0x30, 0x10, 0x06,
0x03, 0x55, 0x04, 0x07, 0x13, 0x09, 0x43, 0x61,
0x6d, 0x62, 0x72, 0x69, 0x64, 0x67, 0x65, 0x31,
0x10, 0x30, 0x0e, 0x06, 0x03, 0x55, 0x04, 0x0a,
0x13, 0x07, 0x41, 0x52, 0x4d, 0x20, 0x4c, 0x74,
0x64, 0x31, 0x21, 0x30, 0x1f, 0x06, 0x03, 0x55,
0x04, 0x03, 0x13, 0x18, 0x41, 0x52, 0x4d, 0x20,
0x49, 0x6e, 0x74, 0x65, 0x67, 0x72, 0x61, 0x74,
0x69, 0x6f, 0x6e, 0x20, 0x4c, 0x57, 0x4d, 0x32,
0x4d, 0x20, 0x43, 0x41, 0x30, 0x20, 0x17, 0x0d,
0x31, 0x37, 0x30, 0x32, 0x31, 0x32, 0x31, 0x30,
0x33, 0x37, 0x35, 0x32, 0x5a, 0x18, 0x0f, 0x32,
0x30, 0x35, 0x32, 0x30, 0x32, 0x31, 0x32, 0x31,
0x30, 0x34, 0x37, 0x35, 0x32, 0x5a, 0x30, 0x6f,
0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04,
0x06, 0x13, 0x02, 0x47, 0x42, 0x31, 0x17, 0x30,
0x15, 0x06, 0x03, 0x55, 0x04, 0x08, 0x13, 0x0e,
0x43, 0x61, 0x6d, 0x62, 0x72, 0x69, 0x64, 0x67,
0x65, 0x73, 0x68, 0x69, 0x72, 0x65, 0x31, 0x12,
0x30, 0x10, 0x06, 0x03, 0x55, 0x04, 0x07, 0x13,
0x09, 0x43, 0x61, 0x6d, 0x62, 0x72, 0x69, 0x64,
0x67, 0x65, 0x31, 0x10, 0x30, 0x0e, 0x06, 0x03,
0x55, 0x04, 0x0a, 0x13, 0x07, 0x41, 0x52, 0x4d,
0x20, 0x4c, 0x74, 0x64, 0x31, 0x21, 0x30, 0x1f,
0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x18, 0x41,
0x52, 0x4d, 0x20, 0x49, 0x6e, 0x74, 0x65, 0x67,
0x72, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x4c,
0x57, 0x4d, 0x32, 0x4d, 0x20, 0x43, 0x41, 0x30,
0x59, 0x30, 0x13, 0x06, 0x07, 0x2a, 0x86, 0x48,
0xce, 0x3d, 0x02, 0x01, 0x06, 0x08, 0x2a, 0x86,
0x48, 0xce, 0x3d, 0x03, 0x01, 0x07, 0x03, 0x42,
0x00, 0x04, 0xba, 0xea, 0x80, 0x01, 0x2d, 0xf0,
0xe1, 0xb6, 0xc5, 0x5f, 0xf9, 0x76, 0x84, 0x31,
0xa9, 0x29, 0xa1, 0xc7, 0xa8, 0xfd, 0xa0, 0xad,
0xd9, 0x94, 0xe7, 0xec, 0x5a, 0x33, 0xa1, 0x2c,
0x8e, 0x36, 0x43, 0x9b, 0x18, 0xdf, 0xce, 0x71,
0x14, 0x24, 0xb1, 0xfb, 0x16, 0x34, 0x0e, 0x43,
0xfc, 0x23, 0x77, 0xd4, 0x13, 0xd7, 0x11, 0xaa,
0x39, 0x60, 0xab, 0xa2, 0xdf, 0x24, 0xb3, 0xeb,
0xa0, 0xc5, 0xa3, 0x51, 0x30, 0x4f, 0x30, 0x0b,
0x06, 0x03, 0x55, 0x1d, 0x0f, 0x04, 0x04, 0x03,
0x02, 0x01, 0x86, 0x30, 0x0f, 0x06, 0x03, 0x55,
0x1d, 0x13, 0x01, 0x01, 0xff, 0x04, 0x05, 0x30,
0x03, 0x01, 0x01, 0xff, 0x30, 0x1d, 0x06, 0x03,
0x55, 0x1d, 0x0e, 0x04, 0x16, 0x04, 0x14, 0x7b,
0xa1, 0xa5, 0x94, 0xa5, 0xe5, 0x8f, 0x95, 0x5d,
0xd4, 0xce, 0xdc, 0x0f, 0x8a, 0xbe, 0xad, 0x9a,
0x6b, 0x66, 0x3e, 0x30, 0x10, 0x06, 0x09, 0x2b,
0x06, 0x01, 0x04, 0x01, 0x82, 0x37, 0x15, 0x01,
0x04, 0x03, 0x02, 0x01, 0x00, 0x30, 0x0a, 0x06,
0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x04, 0x03,
0x02, 0x03, 0x49, 0x00, 0x30, 0x46, 0x02, 0x21,
0x00, 0xd2, 0x06, 0x28, 0xc5, 0x31, 0x3a, 0x11,
0x8d, 0xb6, 0xcb, 0x2b, 0x3f, 0xdd, 0x2a, 0x9a,
0x13, 0x30, 0x52, 0x77, 0xaa, 0xda, 0xda, 0xcb,
0xce, 0xb9, 0x5c, 0xe4, 0x32, 0x1c, 0x02, 0xfa,
0x30, 0x02, 0x21, 0x00, 0xb3, 0x82, 0x24, 0xa2,
0xb1, 0x67, 0x6b, 0x69, 0x07, 0x0e, 0xcd, 0x77,
0x74, 0x99, 0x06, 0x9c, 0x59, 0xb2, 0x00, 0xc0,
0xb3, 0xbb, 0x37, 0x5b, 0xc0, 0x1b, 0xfb, 0xd9,
0x70, 0x98, 0xb9, 0x1e };