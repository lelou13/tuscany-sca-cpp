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

#ifndef tuscany_sca_util_defaultlogwriter_h
#define tuscany_sca_util_defaultlogwriter_h

#include "tuscany/sca/util/LogWriter.h"

namespace tuscany
{
    namespace sca
    {
        /**
         * Log writer to write out to standard out.
         */
        class DefaultLogWriter : public LogWriter
        {
        public:
            virtual ~DefaultLogWriter();

            /**
             * Will write to the console.
             * See LogWriter#log.
             */
            virtual void log(int level, const char* msg);
        };
        
    } // End namespace sca
} // End namespace tuscany
#endif // tuscany_sca_util_defaultlogwriter_h
