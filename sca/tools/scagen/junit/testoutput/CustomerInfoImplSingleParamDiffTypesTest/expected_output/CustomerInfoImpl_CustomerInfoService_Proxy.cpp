/*
 *  Copyright 2005 The Apache Software Foundation or its licensors, as applicable.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#include "CustomerInfoImpl_CustomerInfoService_Proxy.h"

#include "osoa/sca/sca.h"
using namespace osoa::sca;
using namespace tuscany::sca;

extern "C"
{

    #if defined(WIN32) || defined(_WINDOWS)
    __declspec(dllexport) 
    #endif
    CustomerInfoImpl_CustomerInfoService_Proxy* CustomerInfoImpl_CustomerInfoService_Proxy_Factory(ServiceWrapper* target)
    {
        return new CustomerInfoImpl_CustomerInfoService_Proxy(target);
    }

    #if defined(WIN32) || defined(_WINDOWS)
    __declspec(dllexport) 
    #endif
    void CustomerInfoImpl_CustomerInfoService_Proxy_Destructor(void* proxy)
    {
        delete (CustomerInfoImpl_CustomerInfoService_Proxy*)proxy;
    }
}

CustomerInfoImpl_CustomerInfoService_Proxy::CustomerInfoImpl_CustomerInfoService_Proxy(ServiceWrapper* targ) : target(targ)
{
}

CustomerInfoImpl_CustomerInfoService_Proxy::~CustomerInfoImpl_CustomerInfoService_Proxy()
{
    if (target)
        delete target;
}

const char* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInformationChar(const char* arg0)
{
    Operation operation("getCustomerInformationChar");
    operation.addParameter(&arg0);
    const char* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const char* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoAChar(const char* arg0)
{
    Operation operation("getCustomerInfoAChar");
    operation.addParameter(&arg0);
    const char* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const char* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoBChar( char* arg0)
{
    Operation operation("getCustomerInfoBChar");
    operation.addParameter(&arg0);
    const char* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const char* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoCChar( char arg0)
{
    Operation operation("getCustomerInfoCChar");
    operation.addParameter(&arg0);
    const char* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const char* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoDChar( char arg0)
{
    Operation operation("getCustomerInfoDChar");
    operation.addParameter(&arg0);
    const char* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const char* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoEChar( char* arg0)
{
    Operation operation("getCustomerInfoEChar");
    operation.addParameter(&arg0);
    const char* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const char* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoFChar( char* arg0)
{
    Operation operation("getCustomerInfoFChar");
    operation.addParameter(&arg0);
    const char* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const char* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoGChar( signed char* arg0)
{
    Operation operation("getCustomerInfoGChar");
    operation.addParameter(&arg0);
    const char* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const char* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoHChar( unsigned char* arg0)
{
    Operation operation("getCustomerInfoHChar");
    operation.addParameter(&arg0);
    const char* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const long* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInformationLong(const long* arg0)
{
    Operation operation("getCustomerInformationLong");
    operation.addParameter(&arg0);
    const long* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const long* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoALong(const long* arg0)
{
    Operation operation("getCustomerInfoALong");
    operation.addParameter(&arg0);
    const long* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const long* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoBLong( long* arg0)
{
    Operation operation("getCustomerInfoBLong");
    operation.addParameter(&arg0);
    const long* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const long* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoCLong( long arg0)
{
    Operation operation("getCustomerInfoCLong");
    operation.addParameter(&arg0);
    const long* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const long* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoDLong( long arg0)
{
    Operation operation("getCustomerInfoDLong");
    operation.addParameter(&arg0);
    const long* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const long* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoELong( long* arg0)
{
    Operation operation("getCustomerInfoELong");
    operation.addParameter(&arg0);
    const long* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const long* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoFLong( long* arg0)
{
    Operation operation("getCustomerInfoFLong");
    operation.addParameter(&arg0);
    const long* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const long* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoGLong( signed long* arg0)
{
    Operation operation("getCustomerInfoGLong");
    operation.addParameter(&arg0);
    const long* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const long* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoHLong( unsigned long* arg0)
{
    Operation operation("getCustomerInfoHLong");
    operation.addParameter(&arg0);
    const long* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const int* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInformationInt(const int* arg0)
{
    Operation operation("getCustomerInformationInt");
    operation.addParameter(&arg0);
    const int* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const int* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoAInt(const int* arg0)
{
    Operation operation("getCustomerInfoAInt");
    operation.addParameter(&arg0);
    const int* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const int* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoBInt( int* arg0)
{
    Operation operation("getCustomerInfoBInt");
    operation.addParameter(&arg0);
    const int* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const int* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoCInt( int arg0)
{
    Operation operation("getCustomerInfoCInt");
    operation.addParameter(&arg0);
    const int* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const int* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoDInt( int arg0)
{
    Operation operation("getCustomerInfoDInt");
    operation.addParameter(&arg0);
    const int* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const int* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoEInt( int* arg0)
{
    Operation operation("getCustomerInfoEInt");
    operation.addParameter(&arg0);
    const int* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const int* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoFInt( int* arg0)
{
    Operation operation("getCustomerInfoFInt");
    operation.addParameter(&arg0);
    const int* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const int* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoGInt( signed int* arg0)
{
    Operation operation("getCustomerInfoGInt");
    operation.addParameter(&arg0);
    const int* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const int* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoHInt( unsigned int* arg0)
{
    Operation operation("getCustomerInfoHInt");
    operation.addParameter(&arg0);
    const int* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const __int64* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInformationint64(const __int64* arg0)
{
    Operation operation("getCustomerInformationint64");
    operation.addParameter(&arg0);
    const __int64* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const __int64* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoAint64(const __int64* arg0)
{
    Operation operation("getCustomerInfoAint64");
    operation.addParameter(&arg0);
    const __int64* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const __int64* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoBint64( __int64* arg0)
{
    Operation operation("getCustomerInfoBint64");
    operation.addParameter(&arg0);
    const __int64* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const __int64* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoCint64( __int64 arg0)
{
    Operation operation("getCustomerInfoCint64");
    operation.addParameter(&arg0);
    const __int64* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const __int64* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoDint64( __int64 arg0)
{
    Operation operation("getCustomerInfoDint64");
    operation.addParameter(&arg0);
    const __int64* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const __int64* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoEint64( __int64* arg0)
{
    Operation operation("getCustomerInfoEint64");
    operation.addParameter(&arg0);
    const __int64* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const __int64* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoFint64( __int64* arg0)
{
    Operation operation("getCustomerInfoFint64");
    operation.addParameter(&arg0);
    const __int64* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const __int64* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoGint64( signed __int64* arg0)
{
    Operation operation("getCustomerInfoGint64");
    operation.addParameter(&arg0);
    const __int64* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const __int64* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoHint64( unsigned int64* arg0)
{
    Operation operation("getCustomerInfoHint64");
    operation.addParameter(&arg0);
    const __int64* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

const void* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInformationVoid(const __int64* arg0)
{
    Operation operation("getCustomerInformationVoid");
    operation.addParameter(&arg0);
    const void* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

void CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoAVoid(const __int64* arg0)
{
    Operation operation("getCustomerInfoAVoid");
    operation.addParameter(&arg0);
    target->invoke(operation);
    return;
}

void CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoBVoid()
{
    Operation operation("getCustomerInfoBVoid");
    target->invoke(operation);
    return;
}

void CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoCVoid()
{
    Operation operation("getCustomerInfoCVoid");
    target->invoke(operation);
    return;
}

void CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoDVoid()
{
    Operation operation("getCustomerInfoDVoid");
    operation.addParameter(&arg0);
    target->invoke(operation);
    return;
}

const char* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoAInline( char* customer arg0)
{
    Operation operation("getCustomerInfoAInline");
    operation.addParameter(&arg0);
    const char* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

int CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoBInline( char* customer arg0)
{
    Operation operation("getCustomerInfoBInline");
    operation.addParameter(&arg0);
    int ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

friend const unsigned int* CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoCInline( char* customer arg0)
{
    Operation operation("getCustomerInfoCInline");
    operation.addParameter(&arg0);
    friend const unsigned int* ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

int CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoTrickyA(const char arg0)
{
    Operation operation("getCustomerInfoTrickyA");
    operation.addParameter(&arg0);
    int ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

int CustomerInfoImpl_CustomerInfoService_Proxy::getCustomerInfoTrickyB( int arg0)
{
    Operation operation("getCustomerInfoTrickyB");
    operation.addParameter(&arg0);
    int ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}


