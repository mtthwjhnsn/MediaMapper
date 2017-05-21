//
//  ArtnetSender.cpp
//  libArtNetTx
//
//  Created by james on 2015-03-28.
//
//


#include "ArtnetSender.h"
#include <assert.h>

const char* ArtnetSender::skDefaultLongName = "libArtNet";
const char* ArtnetSender::skDefaultShortName = "LibAN";

// Public
ArtnetSender::ArtnetSender()
	: m_node(NULL)
	, m_subnet(0)
	, m_numPorts(0)
{
}

ArtnetSender::~ArtnetSender()
{
}

int ArtnetSender::Init(const char* _ipAddress, uint8_t _subnet, const char* _longName, const char* _shortName)
{
	memset(m_ports, INVALID_PORT_ID, 255);

	// create new artnet node (NULL is local IP) - note: the IP is this machine's IP
	if (0 == strcmp(_ipAddress, ""))
	{
		m_node = artnet_new(NULL, 0);
	}
	else
	{
		m_node = artnet_new(_ipAddress, 0);
	}

	if (NULL == m_node)
	{
		printf("Error creating new artnet node: %s\n", artnet_strerror());
		return -1;
	}

	// set node type as server - we will be sending data
	artnet_set_node_type(m_node, ARTNET_RAW);
	//    artnet_set_node_type( m_node, ARTNET_SRV );

	// long and short name (for network discovery)
	artnet_set_long_name(m_node, _longName);
	artnet_set_short_name(m_node, _shortName);

	// set subnet address
	artnet_set_subnet_addr(m_node, _subnet);

	if (artnet_start(m_node) != ARTNET_EOK)
	{
		printf("Error creating new artnet node: %s\n", artnet_strerror());
		return -1;
	}

	// poll message handler
	artnet_set_handler(m_node, ARTNET_POLL_HANDLER, ArtnetPollWrapper, this);

	m_subnet = _subnet;

	return 0;
}

void ArtnetSender::Shutdown()
{
	if (NULL != m_node)
	{
		artnet_destroy(m_node);

		m_node = NULL;
		m_subnet = 0;
		m_numPorts = 0;

		memset(m_ports, INVALID_PORT_ID, 255);
	}
}

void ArtnetSender::AddUniverse(uint8_t _universe)
{
	assert(NULL != m_node);
	assert(_universe < 16);

	// ensure we are not at 4 port limit imposed by ArtNet
	if (ARTNET_MAX_PORTS <= m_numPorts)
	{
		printf("Error: Maximum number of ArtNet ports has been reached (%u). This is a limitation of ArtNet's design. To get around this, you can create multiple ArtnetSender instances on different virtual adapter IPs. Alternatively, and though not proper, you can use ArtnetSender::SendRawDMX() to send to any subnet and universe.\n", ARTNET_MAX_PORTS);
	}

	assert(ARTNET_MAX_PORTS > m_numPorts);

	// construct port address
	uint8_t portAddress = (m_subnet << 4) | _universe;

	// get libartnet port id for this address
	uint16_t portId = m_ports[portAddress];

	// port does not exist? create it
	if (INVALID_PORT_ID == portId)
	{
		portId = m_numPorts++;
		m_ports[portAddress] = portId;
	}

	// Enable input for this node and assign supplied universe id to it
	// Note: ArtNet nomenclature is network-centric -> input means "input into the network", ie. sending
	artnet_set_port_type(m_node, portId, ARTNET_ENABLE_INPUT, ARTNET_PORT_DMX);
	artnet_set_port_addr(m_node, portId, ARTNET_INPUT_PORT, _universe);
}

void ArtnetSender::SendDMX(uint8_t _universe, const unsigned char* _data, uint16_t _length)
{
	assert(NULL != m_node);
	assert(_length > 0 && _length <= ARTNET_DMX_LENGTH);
	assert(_universe < 16);

	// construct port address from supplied universe and get associated libartnet port
	uint8_t portAddress = (m_subnet << 4) | _universe;
	uint16_t portId = m_ports[portAddress];

	// port does not exist for that universe?
	if (INVALID_PORT_ID == portId)
	{
		printf("Error: port does not exist for universe: %i. Please use ArtnetSender::AddUniverse() to add this universe id before sending.\n", _universe);
	}

	assert(INVALID_PORT_ID != portId);

	// send DMX data
	artnet_send_dmx(m_node, portId, "", _length, _data);
	//artnet_send_dmx(
}
void ArtnetSender::SendRawDMX(uint8_t _subnet, uint8_t _universe, const unsigned char* _data, uint16_t _length)
{
	cout << "mnode = " << m_node << endl;
	assert(NULL != m_node);
	assert(_length > 0 && _length <= ARTNET_DMX_LENGTH);
	assert(_universe < 16);

	uint8_t portAddress = (_subnet << 4) | _universe;

	artnet_raw_send_dmx(m_node, portAddress, _length, _data);
	//artnet_raw_send_dmx()
}

int ArtnetSender::ArtnetPollHandler(artnet_node _node, void * _packet)
{
	return -1; // this will cancel future processing of poll packets
}
