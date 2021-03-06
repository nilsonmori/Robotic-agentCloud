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

/*
    Hello World topic helper module.
*/

'use strict';

const dds = require('vortexdds');
const path = require('path');

module.exports.create = async function(participant) {

  const topicName = 'HelloWorldData_Msg';
  const idlName = 'HelloWorldData.idl';
  const idlPath = __dirname + path.sep + idlName;

  let typeSupports = await dds.getTopicTypeSupportsForIDL(idlPath);

  let typeSupport = typeSupports.get('HelloWorldData::Msg');

  let tqos = dds.QoS.topicDefault();
  tqos.durability = dds.DurabilityKind.Transient;
  tqos.reliability = dds.ReliabilityKind.Reliable;

  return participant.createTopicFor(
    topicName,
    typeSupport,
    tqos
  );
};


