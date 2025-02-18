/*
 *
 *  Copyright 2006 The Apache Software Foundation or its licensors, as applicable.
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

#include "commonj/sdo/SDO.h"

namespace com
{
    namespace bigbank
    {
        namespace account
        {

    /*
     *  AccountDataService C interface
     */

    class AccountDataService {

    public:

        // CheckingAccount is a data object containing
        // String "accountNumber"
        // float balance

        virtual commonj::sdo::DataObjectPtr /* CheckingAccount*/ getCheckingAccount(
            const char *id) = 0;

        // SavingsAccount is a data object containing
        // String accountNumber
        // float balance

        virtual commonj::sdo::DataObjectPtr /* SavingsAccount */ getSavingsAccount(
            const char *id) = 0;

        // StockAccount is a data object containing
        // String accountNumber
        // String symbol
        // int quantity

        virtual commonj::sdo::DataObjectPtr /* StockAccount */ getStockAccount (
            const char* id) = 0;

         
    };

}
} 		 
} // namespace;
