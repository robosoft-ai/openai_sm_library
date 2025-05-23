// Copyright 2021 RobosoftAI Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <smacc2/smacc.hpp>

// CLIENTS
#include <ros_timer_client/cl_ros_timer.hpp>
#include <http_client/cl_http_client.hpp>

// CLIENT BEHAVIORS
#include <ros_timer_client/client_behaviors/cb_timer_countdown_loop.hpp>
#include <ros_timer_client/client_behaviors/cb_timer_countdown_once.hpp>
#include "clients/client_behaviors/cb_openai_http_request.hpp"

// ORTHOGONALS
#include "orthogonals/or_timer.hpp"
#include "orthogonals/or_http.hpp"

using namespace boost;
using namespace smacc2;

namespace sm_atomic_openai {
// STATE
class State1;
class State2;

//--------------------------------------------------------------------
// STATE_MACHINE
struct SmAtomicOpenAI
    : public smacc2::SmaccStateMachineBase<SmAtomicOpenAI, State1> {
  using SmaccStateMachineBase::SmaccStateMachineBase;

  virtual void onInitialize() override {
    this->createOrthogonal<OrTimer>();
    this->createOrthogonal<OrHttp>();
  }
};

}  // namespace sm_atomic_openai

#include "states/st_state_1.hpp"
#include "states/st_state_2.hpp"
