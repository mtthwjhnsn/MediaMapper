//
//  ArtnetSender.h
//  libArtNetTx
//
//  Created by james on 2015-03-28.
//
//

#pragma once

#include <stdio.h>
#include <string>

#include "artnet/artnet.h"
#include "artnet/packets.h"

#define INVALID_PORT_ID   65535
#define SUBNET_MASK       0xF0
#define UNIVERSE_MASK     0x0F



class ArtnetSender
{
private:
	static const char* skDefaultLongName;
	static const char* skDefaultShortName;

public:
	ArtnetSender();
	~ArtnetSender();

	int  Init(const char* _ipAddress = "", uint8_t _subnet = 0, const char* _longName = skDefaultLongName, const char* _shortName = skDefaultShortName);
	void Shutdown();

	void AddUniverse(uint8_t _universe);

	void SendDMX(uint8_t _universe, const unsigned char* _data, uint16_t _length);
	void SendRawDMX(uint8_t _subnet, uint8_t _universe, const unsigned char* _data, uint16_t _length);

	int  ArtnetPollHandler(artnet_node node, void *_packet);

	static int ArtnetPollWrapper(artnet_node _node, void* _packet, void* _scope)
	{
		
		printf("Artnet Poll\n");
		ArtnetSender* obj = (ArtnetSender *)_scope;
		return obj->ArtnetPollHandler(_node, _packet);
	};

private:

	artnet_node          m_node;

	uint8_t              m_subnet;

	// port id indexed by port address (max of 255)
	uint16_t             m_ports[255];
	uint8_t              m_numPorts;
};