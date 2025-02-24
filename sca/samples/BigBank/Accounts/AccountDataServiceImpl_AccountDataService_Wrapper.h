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

#ifndef AccountDataServiceImpl_AccountDataService_Wrapper_h
#define AccountDataServiceImpl_AccountDataService_Wrapper_h

#include "AccountDataServiceImpl.h"
#include "tuscany/sca/core/ComponentServiceWrapper.h"

class AccountDataServiceImpl_AccountDataService_Wrapper : public tuscany::sca::ComponentServiceWrapper
{
public:
    AccountDataServiceImpl_AccountDataService_Wrapper(tuscany::sca::model::Service* target);
    virtual ~AccountDataServiceImpl_AccountDataService_Wrapper();
    virtual void invokeService(tuscany::sca::Operation& operation);
    virtual void* newImplementation();
    virtual void deleteImplementation();
private:
    com::bigbank::account::AccountDataServiceImpl* impl;
};

#endif // AccountDataServiceImpl_AccountDataService_Wrapper_h

