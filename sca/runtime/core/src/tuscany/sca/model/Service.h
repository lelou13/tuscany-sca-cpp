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

/* $Rev$ $Date: 2005/12/22 11:33:21 $ */

#ifndef tuscany_sca_model_service_h
#define tuscany_sca_model_service_h

#include <string>
using std::string;

#include "tuscany/sca/model/WireTarget.h"

namespace tuscany
{
    namespace sca
    {
        namespace model
        {
            class Component;

            /**
             * Information about a service defined on a component.
             */
            class Service : public WireTarget
            {
            public:
                /**
                 * Destructor.
                 */
                 virtual ~Service();

                /**
                 * Return the type of the wire target.
                 * @return Always returns ComponentServiceType.
                 */
                virtual Type getServiceType() {return ComponentServiceType;}

                /**
                 * Get the component on which this service is defined.
                 * @return The component on which this service is defined.
                 */
                Component* getComponent() {return component;}


            private:
                friend class Component;
                /**
                 * Constructor.
                 * @param name The name of the service.
                 * @param component The component on which this service is defined.
                 */
                Service(const std::string& name, Component* component);

                /**
                 * The component on which this service is defined.
                 */
                 Component* component;

            };

         } // End namespace model
    } // End namespace sca
} // End namespace tuscany

#endif // tuscany_sca_model_service_h

