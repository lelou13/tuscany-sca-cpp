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

/* $Rev$ $Date: 2005/12/22 16:54:14 $ */

#ifndef _DASPROPERTY_H_
#define _DASPROPERTY_H_
#include "commonj/sdo/Property.h"
#include "commonj/sdo/DASValues.h"

#include "commonj/sdo/disable_warn.h"

namespace commonj{
namespace sdo{
    
/** 
 * DASProperty is a class to provide data access services
 * with a more flexible Property
 */

    class DASProperty : public Property, public DASValues
{
     public:

    virtual ~DASProperty();



};
};
};
#endif //_DMSDATAOBJECT_H_
