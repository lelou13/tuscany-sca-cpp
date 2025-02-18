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

// Component.cpp : Represent a loaded Component
//
#include "tuscany/sca/util/Logging.h"
#include "tuscany/sca/util/Exceptions.h"
#include "tuscany/sca/util/Utils.h"
#include "tuscany/sca/model/Component.h"

using namespace commonj::sdo;

namespace tuscany
{
    namespace sca
    {
        namespace model
        {
           // Constructor
            Component::Component(const std::string& componentName, Module* module) 
                : name(componentName), containingModule(module), implementation(0)
            {
                LOGENTRY(1, "Component::constructor");
                LOGINFO_1(3, "Component::constructor: Component name: %s", name.c_str());
                LOGEXIT(1, "Component::constructor");
            }

            Component::~Component()
            {
            }

            Service* Component::addService(const std::string& serviceName)
            {
                Service* service = new Service(serviceName, this);
                services[serviceName] = service;
                return service;
            }
            
            Service* Component::findService(const std::string& serviceName)
            {
                // If serviceName is null then return the ONLY service
                if (serviceName == "" 
                    && services.size() == 1)
                {
                    return services.begin()->second;
                }
                else
                {
                    return services[serviceName];
                }
            }
            
            ServiceReference* Component::findReference(const std::string& referenceName)
            {
                return references[referenceName];
            }
            
            ServiceReference* Component::addReference(const std::string& referenceName)
            {
                ServiceReference* serviceReference = references[referenceName];
                if (!serviceReference)
                {
                    references[referenceName] = new ServiceReference(referenceName);
                }
                return references[referenceName];
            }
            
            void Component::setImplementation(Implementation* impl)
            {
                implementation = impl;
            }
            
            void Component::addProperty(const string& name,
                const string& type,
                bool many,
                bool required,
                const char* defaultValue)
            {
                // Create a Type in the Properties dataFactory
                DataFactoryPtr factory = getPropertyDataFactory();
                
                string typeUri, typeName;
                Utils::tokeniseQName(type, typeUri, typeName);
                
                if (typeUri == "http://www.w3.org/2001/XMLSchema")                                
                {
                    typeUri = Type::SDOTypeNamespaceURI;
                    if (typeName == "string")
                    {
                        typeName = "String";
                    }
                    else if (typeName == "anyType")
                    {
                        typeName = "DataObject";
                    }
                    else if (typeName == "int")
                    {
                        typeName = "Integer";
                    }
                    else if (typeName == "integer")
                    {
                        typeName = "Integer";
                    }
                    else if (typeName == "negativeInteger")
                    {
                        typeName = "Integer";
                    }
                    else if (typeName == "nonNegativeInteger")
                    {
                        typeName = "Integer";
                    }
                    else if (typeName == "positiveInteger")
                    {
                        typeName = "Integer";
                    }
                    else if (typeName == "nonPositiveInteger")
                    {
                        typeName = "Integer";
                    }
                    else if (typeName == "unsignedLong")
                    {
                        typeName = "Integer";
                    }
                    else if (typeName == "unsignedShort")
                    {
                        typeName = "Integer";
                    }
                    else if (typeName == "unsignedInt")
                    {
                        typeName = "Long";
                    }
                    else if (typeName == "long")
                    {
                        typeName = "Long";
                    }
                    else if (typeName == "double")
                    {
                        typeName = "Double";
                    }
                    else if (typeName == "short")
                    {
                        typeName = "Short";
                    }
                    else if (typeName == "unsignedByte")
                    {
                        typeName = "Short";
                    }
                    else if (typeName == "float")
                    {
                        typeName = "Float";
                    }
                    else if (typeName == "boolean")
                    {
                        typeName = "Boolean";
                    }
                    else if (typeName == "byte")
                    {
                        typeName = "Byte";
                    }
                    else if (typeName == "base64Binary")
                    {
                        typeName = "Bytes";
                    }
                    else if (typeName == "hexBinary")
                    {
                        typeName = "Bytes";
                    }
                    else if (typeName == "anyURI")
                    {
                        typeName = "URI";
                    }
                    else if (typeName == "QName")
                    {
                        typeName = "URI";
                    }
                    else
                    {
                        // Default unknown xs: types to string??
                        typeName = "String";
                    }
                }
                else
                {
                    // It's not an XML type
                }


                factory->addPropertyToType(
                    "org/osoa/sca",
                    "Properties",
                    name.c_str(),
                    typeUri.c_str(), 
                    typeName.c_str(),
                    many,
                    false,
                    true);

                // Set the default
                
                
                // Add to list of required properties
                if (required)
                {
                }
            }
            
            DataFactoryPtr Component::getPropertyDataFactory()
            {
                if (!propertyFactory)
                {
                    propertyFactory = DataFactory::getDataFactory();
                    // Add the root type
                    propertyFactory->addType("org/osoa/sca", "Properties", false, false, false, false);
                }
                return propertyFactory;
            }
            
            DataObjectPtr Component::getProperties()
            {
                if (!properties)
                {
                    properties = getPropertyDataFactory()->create("org/osoa/sca", "Properties");
                }
                return properties;
            }
            
            void Component::addProperties(DataObjectPtr values)
            {
                if (!values)
                {
                    return;
                }

                DataObjectPtr props = getProperties();

                PropertyList pl = values->getInstanceProperties();
                for (int i=0; i < pl.size(); i++)
                {
                    if (!values->isSet(i))
                    {
                        continue;
                    }

                    // Add the property value to the component to be resolved later
                    string propName = pl[i].getName();

                    // Get the property's type
                    try
                    {
                        const Property& propProperty = props->getProperty(pl[i].getName());
                        const Type& propType = propProperty.getType();
 
                        DataObjectList& proplist = values->getList(pl[i]);
                        for (int proplistI=0; proplistI<proplist.size(); proplistI++)
                        {
                            // Get the property value
                            string propValue = proplist.getDataObject(proplistI)->getSequence()->getCStringValue(0);
                            if (propType.isDataType())
                            {
                                if (propProperty.isMany())
                                {
                                    DataObjectList& dol = props->getList(propProperty);
                                    dol.append(propValue.c_str());
                                }
                                else
                                {
                                    props->setCString(propProperty, propValue.c_str());
                                }
                            }
                            else
                            {
                                // Create a new instance of the DO
                                // iterate over properties setting each one
                            }
                        }
                    }
                    catch (SDOPropertyNotFoundException&)
                    {
                        // Configuration error: property is not defined
                        string message = "Undefined property: " + propName;
                        throw SystemConfigurationException(message.c_str());
                    }
                    
                }
            }

        } // End namespace model
    } // End namespace sca
} // End namespace tuscany
