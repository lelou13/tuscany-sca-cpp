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

/* $Rev$ $Date$ */

#if defined(WIN32)  || defined (_WINDOWS)
#pragma warning(disable: 4786)
#endif

#include "sdo_axiom.h"

using namespace commonj::sdo;
using namespace std;


namespace commonj
{
    namespace sdo_axiom
    {

        int AxiomHelper::axiswritercount = 0;

        AxiomHelper* AxiomHelper::getHelper()
        {
            return new AxiomHelper();
        }

        void AxiomHelper::releaseHelper(AxiomHelper* h)
        {
            if (h) delete h;
        }

        void AxiomHelper::deleteEnv()
        {
            if (the_env)axis2_env_free(the_env);
        }

        void AxiomHelper::createEnv()
        {
    
            the_allocator = axis2_allocator_init (NULL);
            if (the_allocator == NULL) return;

            the_env = axis2_env_create(the_allocator); 

            if (the_env == 0) return;

            return;
        }


        AxiomHelper::AxiomHelper()
        {
            createEnv();
        }

        AxiomHelper::~AxiomHelper()
        {
            deleteEnv();
        }


        axis2_env_t* AxiomHelper::getEnv()
        {
            return the_env;
        }

        axiom_node_t* AxiomHelper::toAxiomNode(DataObjectPtr dob)
        {

            axiom_document_t* doc = toAxiomDoc(dob);

            if (!doc)
            {
                return 0;
            }
    
            axiom_node_t* root_node = 
                AXIOM_DOCUMENT_GET_ROOT_ELEMENT(doc, the_env);
            if (!root_node)
            {
                cout << "No Root Element in the document" << endl;
                return 0;
            }
            

            return root_node;
        }

        axiom_document_t* AxiomHelper::toAxiomDoc(DataObjectPtr dob)
        {

            DataFactory* df = dob->getDataFactory();
            XSDHelperPtr xs = HelperProvider::getXSDHelper(df);
            XMLHelperPtr xm = HelperProvider::getXMLHelper(df);
            if (!the_env)
            {
                cout << "No Axis Environment" << endl;
                return 0;
            }
           char * str = 
                xm->save(
                dob,
                dob->getType().getURI(),
                dob->getType().getName());

            // if (str) cout << str << endl;

            axiom_xml_reader_t * reader =  
            axiom_xml_reader_create_for_memory(the_env,
                                  (void*)str,
                                  strlen(str),
                                  (const axis2_char_t *)"UTF-8",
                                  AXIS2_XML_PARSER_TYPE_BUFFER);
        
            if (!reader)
            {
                cout << "No Axis Reader" << endl;
                return 0;
            }

            axiom_stax_builder_t* builder = 
                axiom_stax_builder_create(the_env, reader);
        
            if (!builder)
            {
                cout << "No Axis Builder" << endl;
                AXIOM_XML_READER_FREE(reader, the_env);
                return 0;
            }
        
            axiom_document_t* document = 
                AXIOM_STAX_BUILDER_GET_DOCUMENT(builder, the_env);
        
            if (!document)
            {
                cout << "No Axis Document" << endl;
                AXIOM_STAX_BUILDER_FREE(builder, the_env);
                return 0;
            }
    
            axiom_node_t* root_node = 
                AXIOM_DOCUMENT_GET_ROOT_ELEMENT(document, the_env);
            if (!root_node)
            {
                cout << "No Root Element in the document" << endl;
                AXIOM_STAX_BUILDER_FREE(builder, the_env);
                return 0;
            }
            

            AXIOM_DOCUMENT_BUILD_ALL(document, the_env);

            return document;
        }

        DataObjectPtr AxiomHelper::toSdo(axiom_document_t* document,
            DataFactoryPtr factory)
        {
        
            if (!the_env)
            {
                cout << "No Axis Environment" << endl;
                return 0;
            }

            axiom_node_t* root_node = 
                AXIOM_DOCUMENT_GET_ROOT_ELEMENT(document, the_env);

            return toSdo(root_node,factory);
        }
 
        DataObjectPtr AxiomHelper::toSdo(axiom_node_t* root_node,
                                DataFactoryPtr factory)
        {
        
            if (!the_env)
            {
                cout << "No Axis Environment" << endl;
                return 0;
            }

            XMLHelperPtr helper = HelperProvider::getXMLHelper(factory);

            axiom_xml_writer_t* writer = axiom_xml_writer_create_for_memory(
                the_env, NULL, AXIS2_TRUE, 0,
                AXIS2_XML_PARSER_TYPE_BUFFER);
    
            axiom_output_t* output = axiom_output_create(the_env, writer);
    

            if (!root_node)
            {
                cout << "No Root Element in the document" << endl;
                AXIOM_OUTPUT_FREE(output, the_env);
                return 0;
            }

            AXIOM_NODE_SERIALIZE(root_node, the_env, output);
    
            axis2_char_t* buffer = (axis2_char_t*)AXIOM_XML_WRITER_GET_XML(writer, the_env);

            XMLDocumentPtr theXMLDocument = helper->load(buffer);

            if (theXMLDocument != 0)
            {
                return theXMLDocument->getRootDataObject();
            }
            cout << "The XML document returned from load was zero" << endl;
            return 0;
        }
 
        void AxiomHelper::output(axiom_document_t* document)
        {
        
            if (!the_env)
            {
                cout << "No Axis Environment" << endl;
                return;
            }

            axiom_xml_writer_t* writer = axiom_xml_writer_create_for_memory(
                the_env, NULL, AXIS2_TRUE, 0,
                AXIS2_XML_PARSER_TYPE_BUFFER);
    
            axiom_output_t* output = axiom_output_create(the_env, writer);
    
            axiom_node_t* root_node = 
                AXIOM_DOCUMENT_GET_ROOT_ELEMENT(document, the_env);
 
            if (!root_node)
            {
                cout << "No Root Element in the document" << endl;
                AXIOM_OUTPUT_FREE(output, the_env);
                return;
            }

            AXIOM_NODE_SERIALIZE(root_node, the_env, output);
    
            axis2_char_t* buffer = (axis2_char_t*)AXIOM_XML_WRITER_GET_XML(writer, the_env);

            printf("Output XML:n %s ", buffer);

            AXIOM_OUTPUT_FREE(output, the_env);
       
            return;          
        }
    }
}

