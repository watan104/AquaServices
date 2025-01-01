#pragma once
#include <string>
#include <cstring>
#include <enet/enet.h>

class Peer2Peer {
public:
	Peer2Peer(ENetPeer* peer);
	Peer2Peer();

	bool Valid() const;
	uint8_t* GetPeerData();
	void SetPeerData(uint8_t* data);

	ENetPeer* GetPeer();
	std::string GetIp() const;
	uint32_t GetIpAsInt() const;
	uint32_t GetPeerConnectId() const;
	uint32_t GetPeerPing() const;
	uint32_t GetIncomingBandwidth() const;
	uint32_t GetOutgoingBandwidth() const;

	void RequestDisconnect();
private:
	ENetPeer* m_pPeer;
};