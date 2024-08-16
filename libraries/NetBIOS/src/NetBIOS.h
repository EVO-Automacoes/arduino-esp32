//
#ifndef __ESPNBNS_h__
#define __ESPNBNS_h__

#include <WiFi.h>
#include "AsyncUDP.h"

class NetBIOS
{
protected:
    AsyncUDP _udp;
    String _name;
    tcpip_adapter_if_t _tcpip_adapter;
    void _onPacket(AsyncUDPPacket& packet);

public:
    NetBIOS();
    ~NetBIOS();
    bool begin(const char *name,tcpip_adapter_if_t tcpip_adapter = TCPIP_ADAPTER_IF_STA);
    void end();
};

#if !defined(NO_GLOBAL_INSTANCES) && !defined(NO_GLOBAL_NETBIOS)
extern NetBIOS NBNS;
#endif

#endif
