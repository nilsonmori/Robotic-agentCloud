/*
 *                         Vortex OpenSplice
 *
 *   This software and documentation are Copyright 2006 to  ADLINK
 *   Technology Limited, its affiliated companies and licensors. All rights
 *   reserved.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 */
#ifndef CPP_DDS_OPENSPLICE_CDRTYPESUPPORT_H
#define CPP_DDS_OPENSPLICE_CDRTYPESUPPORT_H

#include "ccpp.h"
#include "TypeSupport.h"
#include "cpp_dcps_if.h"

/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

namespace DDS
{
    namespace OpenSplice
    {
        class OS_API CdrSerializedData
        {
        public:
           virtual ~CdrSerializedData() {}
           virtual unsigned int get_size() = 0;
           virtual void get_data(void *buffer) = 0;
        };

        class OS_API CdrTypeSupport
        {
        public:
            CdrTypeSupport(DDS::TypeSupport& ts);
            virtual ~CdrTypeSupport();

            virtual ::DDS::ReturnCode_t
             serialize(
                 const void *message,
                 DDS::OpenSplice::CdrSerializedData **serdata);

             virtual ::DDS::ReturnCode_t
             deserialize(
                 const void *serialized_message,
                 unsigned int message_size,
                 void *message);
        private:
             DDS::OpenSplice::TypeSupportMetaHolder *tsMetaHolder;
        }; /* class CdrTypeSupport */
    } /* namespace OpenSplice */
} /* namespace DDS */

#undef OS_API
#endif /* CPP_DDS_OPENSPLICE_CDRTYPESUPPORT_H */
