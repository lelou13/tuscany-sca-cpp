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

#ifndef CalculatorImpl_CalculatorService_Proxy_h
#define CalculatorImpl_CalculatorService_Proxy_h

#if defined(WIN32) || defined (_WINDOWS)
#pragma warning(disable: 4786)
#endif 

#include "Calculator.h"
#include "tuscany/sca/core/ServiceWrapper.h"

class CalculatorImpl_CalculatorService_Proxy : public Calculator
{
public:
    CalculatorImpl_CalculatorService_Proxy(tuscany::sca::ServiceWrapper*);
    virtual ~CalculatorImpl_CalculatorService_Proxy();
    virtual float add( float arg1,  float arg2);
    virtual float sub( float arg1,  float arg2);
    virtual float mul( float arg1,  float arg2);
    virtual float div( float arg1,  float arg2);
private:
    tuscany::sca::ServiceWrapper* target;
};

#endif // CalculatorImpl_CalculatorService_Proxy_h

