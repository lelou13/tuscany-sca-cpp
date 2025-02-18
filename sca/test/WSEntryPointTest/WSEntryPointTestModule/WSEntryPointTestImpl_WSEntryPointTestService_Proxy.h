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

#ifndef WSEntryPointTestImpl_WSEntryPointTestService_Proxy_h
#define WSEntryPointTestImpl_WSEntryPointTestService_Proxy_h

#if defined(WIN32) || defined (_WINDOWS)
#pragma warning(disable: 4786)
#endif 

#include "WSEntryPointTest.h"
#include "tuscany/sca/core/ServiceWrapper.h"

class WSEntryPointTestImpl_WSEntryPointTestService_Proxy : public WSEntryPointTest
{
public:
    WSEntryPointTestImpl_WSEntryPointTestService_Proxy(tuscany::sca::ServiceWrapper*);
    virtual ~WSEntryPointTestImpl_WSEntryPointTestService_Proxy();
    virtual char* doChars( char* arg1);
    virtual long doLong( long arg1);
    virtual int doInt( int arg1);
    virtual float doFloat( float arg1);
    virtual long double doLongDouble( long double arg1);
    virtual double doDouble( double arg1);
    virtual bool doBool( bool arg1);
    virtual short doShort( short arg1);
    virtual char* doBytes( char* arg1);
    virtual char doByte( char arg1);
    virtual DataObjectPtr doMixed( char* arg1,  long arg2,  DataObjectPtr arg3,  bool arg4,  double arg5);
    virtual DataObjectPtr doDataObject( DataObjectPtr arg1);
    virtual DataObjectPtr doAny( DataObjectPtr arg1);
private:
    tuscany::sca::ServiceWrapper* target;
};

#endif // WSEntryPointTestImpl_WSEntryPointTestService_Proxy_h

