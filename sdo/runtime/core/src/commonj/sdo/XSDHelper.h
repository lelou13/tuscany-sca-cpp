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

#ifndef _XSDHELPER_H_
#define _XSDHELPER_H_


#include "commonj/sdo/export.h"
#include "commonj/sdo/RefCountingObject.h"
#include "commonj/sdo/DataFactory.h"
#include "commonj/sdo/TypeDefinitions.h"

namespace commonj
{
    namespace sdo
    {
        
        /**  
         *
         * XSDHelper provides the means of loading and saving XSD information 
         * from/to the metadata (Types and properties)
         */
        
        class XSDHelper : public RefCountingObject
        {
        public:
            
            /**  define builds types/properties from file or stream
             *
             * define/defineFile
             *
             * Populates the data factory with Types and Properties from the schema
             * Loads from file, stream or char* buffer.
             * The return value is the URI of the root Type
             *
             */

            SDO_API virtual const char* defineFile(const char* schemaFile) = 0;
            SDO_API virtual const char* define(std::istream& schema) = 0;
            SDO_API virtual const char* define(const char* schema) = 0;
            

            /**  generate buildsXSD from types/properties
             *
             * generate/generateFile
             *
             * Saves the types/properties to an XSD stream or file
             *
             */

            SDO_API virtual char* generate(
                const TypeList& types,
                const char* targetNamespaceURI = "",
                int indent = -1) = 0;
            SDO_API virtual void generate(
                const TypeList& types,
                std::ostream& outXsd,
                const char* targetNamespaceURI = "",
                int indent = -1) = 0;
            SDO_API virtual void generateFile(
                const TypeList& types,
                const char* fileName,
                const char* targetNamespaceURI = "",
                int indent = -1) = 0;

            /***********************************/
            /* Destructor */
            /***********************************/
            SDO_API virtual ~XSDHelper();

            /**  getDataFactory() 
             *
             * Return the DataFactory
             */

            SDO_API virtual DataFactoryPtr getDataFactory() = 0;

            /**  getRootTypeURI
             *
             * Return the URI for the root Type
             */

            SDO_API virtual const char* getRootTypeURI() = 0;
            
            /** getErrorCount gets number of parse errors
             *
             * Parser error count - the parse may have 
             * succeeded or partially succeeded or failed. There
             * may be errors to report or handle.
             */

            virtual int  getErrorCount() const = 0;

            /** getErrorMessage gets the nth error message
             *
             * Each error has a message, usually giving the line and file
             * in which the parser error occurred.
             */

            virtual const char* getErrorMessage(int errnum) const = 0;

            /**
             *
             * used for defining types from type definitions
             */

            SDO_API virtual void defineTypes(TypeDefinitions& types) = 0;


        };
    }//End - namespace sdo
} // End - namespace commonj

#endif //_XSDHELPER_H_
