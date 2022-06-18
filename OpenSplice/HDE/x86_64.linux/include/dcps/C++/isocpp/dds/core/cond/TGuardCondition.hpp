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
#ifndef OSPL_DDS_CORE_COND_TGUARDCONDITION_HPP_
#define OSPL_DDS_CORE_COND_TGUARDCONDITION_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <spec/dds/core/cond/TGuardCondition.hpp>

// Implementation
namespace dds
{
namespace core
{
namespace cond
{

template <typename DELEGATE>
TGuardCondition<DELEGATE>::TGuardCondition() : TCondition< DELEGATE >(new DELEGATE()) { }

template <typename DELEGATE>
TGuardCondition<DELEGATE>::~TGuardCondition()
{
    this->reset_handler();
}

template <typename DELEGATE>
template <typename Functor>
void TGuardCondition<DELEGATE>::handler(const Functor& func)
{
    this->delegate()->set_handler(func);
}

template <typename DELEGATE>
void TGuardCondition<DELEGATE>::reset_handler()
{
    this->delegate()->reset_handler();
}

template <typename DELEGATE>
void TGuardCondition<DELEGATE>::trigger_value(bool value)
{
    this->delegate()->trigger_value(value);
}

template <typename DELEGATE>
bool TGuardCondition<DELEGATE>::trigger_value() const
{
    return this->delegate()->get_trigger_value();
}

}
}
}
// End of implementation

#endif /* OSPL_DDS_CORE_COND_TGUARDCONDITION_HPP_ */
