//
// Created by arthur on 12/08/2023.
//

#ifndef CONCERTO_CORE_NETWORK_ENET_HPP
#define CONCERTO_CORE_NETWORK_ENET_HPP

#include "Concerto/Core/Types.hpp"

namespace cct::Network
{
	class CONCERTO_CORE_PUBLIC_API ENet
	{
	 public:
		static void Initialize();
		static void Deinitialize();
	};
}// namespace cct::Network

#endif//CONCERTO_CORE_NETWORK_ENET_HPP