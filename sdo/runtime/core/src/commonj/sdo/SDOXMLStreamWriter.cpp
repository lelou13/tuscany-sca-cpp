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

/* $Rev$ $Date: 2006/02/01 16:24:13 $ */

#include "commonj/sdo/SDOXMLStreamWriter.h"
#include <sstream>

namespace commonj
{
    namespace sdo
    {
        
        
        
        
        SDOXMLStreamWriter::SDOXMLStreamWriter(std::ostream& outXML, DataFactoryPtr dataFactory)
            : SDOXMLBufferWriter(dataFactory), outXmlStream(outXML)
        {
        }
        
        SDOXMLStreamWriter::~SDOXMLStreamWriter()
        {    
        }
        
        int SDOXMLStreamWriter::write(XMLDocumentPtr doc, int indent)
        {
            int rc = SDOXMLBufferWriter::write(doc, indent);

            // Now stream the buffer
            outXmlStream << getBuffer();
            return rc;
        }            
    } // End - namespace sdo
} // End - namespace commonj

