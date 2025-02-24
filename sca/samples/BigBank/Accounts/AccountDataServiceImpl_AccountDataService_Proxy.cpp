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

#if defined(WIN32)  || defined (_WINDOWS)
#pragma warning(disable: 4786)
#endif

#include "AccountDataServiceImpl_AccountDataService_Proxy.h"

#include "osoa/sca/sca.h"
using namespace osoa::sca;
using namespace tuscany::sca;

extern "C"
{

    #if defined(WIN32) || defined(_WINDOWS)
    __declspec(dllexport) 
    #endif
    AccountDataServiceImpl_AccountDataService_Proxy* AccountDataServiceImpl_AccountDataService_Proxy_Factory(ServiceWrapper* target)
    {
        return new AccountDataServiceImpl_AccountDataService_Proxy(target);
    }

    #if defined(WIN32) || defined(_WINDOWS)
    __declspec(dllexport) 
    #endif
    void AccountDataServiceImpl_AccountDataService_Proxy_Destructor(void* proxy)
    {
        delete (AccountDataServiceImpl_AccountDataService_Proxy*)proxy;
    }
}

AccountDataServiceImpl_AccountDataService_Proxy::AccountDataServiceImpl_AccountDataService_Proxy(ServiceWrapper* targ) : target(targ)
{
}

AccountDataServiceImpl_AccountDataService_Proxy::~AccountDataServiceImpl_AccountDataService_Proxy()
{
    if (target)
        delete target;
}

commonj::sdo::DataObjectPtr AccountDataServiceImpl_AccountDataService_Proxy::getCheckingAccount(const char* arg0)
{
    Operation operation("getCheckingAccount");
    operation.addParameter(&arg0);
    commonj::sdo::DataObjectPtr ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

commonj::sdo::DataObjectPtr AccountDataServiceImpl_AccountDataService_Proxy::getSavingsAccount(const char* arg0)
{
    Operation operation("getSavingsAccount");
    operation.addParameter(&arg0);
    commonj::sdo::DataObjectPtr ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}

commonj::sdo::DataObjectPtr AccountDataServiceImpl_AccountDataService_Proxy::getStockAccount(const char* arg0)
{
    Operation operation("getStockAccount");
    operation.addParameter(&arg0);
    commonj::sdo::DataObjectPtr ret;
    operation.setReturnValue(&ret);
    target->invoke(operation);
    return ret;
}


