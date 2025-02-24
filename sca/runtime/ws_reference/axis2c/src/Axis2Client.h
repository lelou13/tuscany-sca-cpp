/*
 *
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

#ifndef tuscany_sca_ws_axis2client_h
#define tuscany_sca_ws_axis2client_h

#include "osoa/sca/export.h"

#include <axiom.h>

#include <osoa/sca/export.h>

#include "tuscany/sca/core/ExternalServiceWrapper.h"
#include "tuscany/sca/model/ExternalService.h"

#include "tuscany/sca/model/Wsdl.h"
#include "tuscany/sca/core/Operation.h"
using namespace tuscany::sca;
using namespace tuscany::sca::model;


namespace tuscany
{
    namespace sca
    {
        namespace ws
        {
        
            class SCA_API Axis2Client
            {
            public:
                Axis2Client(tuscany::sca::model::ExternalService* externalService);
                virtual    ~Axis2Client();

                virtual void invoke(tuscany::sca::Operation& operation);    
                
            private:
                tuscany::sca::model::ExternalService* externalService;
                              
                axiom_node_t* createPayload(Operation& operation, 
                                               const WsdlOperation& wsdlOp,
                                               axis2_env_t* env);
                                                 
                void setReturn(axiom_node_t* returnNode,
                               Operation& operation, 
                               const WsdlOperation& wsdlOp,
                               axis2_env_t* env);
                
            };
        } // End namespace ws
    } // End namespace sca
} // End namespace tuscany

#endif // tuscany_sca_ws_axis2client_h
