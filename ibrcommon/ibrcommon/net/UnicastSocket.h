/*
 * UnicastSocket.h
 *
 *   Copyright 2011 Johannes Morgenroth
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

#ifndef UNICASTSOCKET_H_
#define UNICASTSOCKET_H_

#include "ibrcommon/net/vinterface.h"
#include "ibrcommon/net/vaddress.h"
#include "ibrcommon/net/udpsocket.h"

namespace ibrcommon
{
	class UnicastSocket : public ibrcommon::udpsocket
	{
	public:
		UnicastSocket();
		virtual ~UnicastSocket();

		void bind(int port, const vaddress &address);
		void bind(int port, const vinterface &iface);
		void bind();
	};
}

#endif /* UNICASTSOCKET_H_ */
