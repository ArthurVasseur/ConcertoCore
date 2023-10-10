//
// Created by arthur on 12/08/2023.
//

#include "Concerto/Core/Network/ENet/Client.hpp"
#include "Concerto/Core/Logger.hpp"

#include <enet/enet.h>

namespace Concerto::Network
{
	EnetClient::EnetClient(UInt32 maxIncomingBandwidth, UInt32 maxOutgoingBandwidth) : 
		ENetHost(nullptr, 1, 2, maxIncomingBandwidth, maxOutgoingBandwidth),
		_peer(nullptr)
	{
	}

	bool EnetClient::SendPacket(const ENetPacket& packet, UInt8 channel, ENetPacket::Flag flags)
	{
		return ENetHost::SendPacket(packet, _peer.get(), channel, flags);
	}
	
	void EnetClient::Connect(IpAddress address)
	{
		ENetAddress enetAddress = {};
		std::string addressStr = address.ToString();
		enet_address_set_host(&enetAddress, addressStr.c_str());
		enetAddress.port = address.GetPort();
		auto peer = enet_host_connect(static_cast<::ENetHost*>(_enetHost), &enetAddress, _maxChannels, 0);
		if (peer == nullptr)
		{
			CONCERTO_ASSERT_FALSE;
			Logger::Error("Cannot create an Enet connection");
			return;
		}
		_peer = std::make_unique<ENetPeer>(peer);
	}

	void EnetClient::Disconnect()
	{
		CONCERTO_ASSERT(_peer);
		_peer->Disconnect();
	}

}// namespace Concerto::Network