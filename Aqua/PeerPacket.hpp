#include <enet/enet.h>
#include "Packet.hpp"
#include <algorithm>
#include "Variant.hpp"

class PeerPacket {
public:
	PeerPacket(ENetPeer* peer) : m_peer(peer) {}
	~PeerPacket() = default;

	_NODISCARD ENetPeer* GetPeer();

	void Send(TankUpdatePacket tank_packet, uintmax_t data_size);
	void Send(TankUpdatePacket* tank_packet, uintmax_t data_size);
	void Send(int32_t type, const void* data, uintmax_t data_size);
	void Variant(const variantlist_t& var, int32_t delay = 0, int32_t net_id = -1);
private:
	ENetPeer* m_peer;
};