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

/* $Rev$ $Date: 2005/12/22 16:54:15 $ */

#include "commonj/sdo/SDODate.h"

namespace commonj{
namespace sdo{


     SDODate::~SDODate()
     {
     }

     SDODate::SDODate(time_t inval)
     {
         value = inval;
     }

    ///////////////////////////////////////////////////////////////////////////
    //
    ///////////////////////////////////////////////////////////////////////////

    const time_t SDODate::getTime(void) const
    {
        return value;
    }

    const char* SDODate::ascTime(void) const
    {
        return asctime(localtime(&value));
    }

};
};
// end - namespace sdo

