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

#ifndef MyValueImpl_stockQuote_Proxy_h
#define MyValueImpl_stockQuote_Proxy_h

#if defined(WIN32) || defined (_WINDOWS)
#pragma warning(disable: 4786)
#endif 

#include "StockQuoteService.h"
#include "tuscany/sca/core/ServiceWrapper.h"

class MyValueImpl_stockQuote_Proxy : public StockQuoteService
{
public:
    MyValueImpl_stockQuote_Proxy(tuscany::sca::ServiceWrapper*);
    virtual ~MyValueImpl_stockQuote_Proxy();
    virtual string GetQuote(const char* request);
private:
    tuscany::sca::ServiceWrapper* target;
};

#endif // MyValueImpl_stockQuote_Proxy_h

