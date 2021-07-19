#include "ethernet.h"
using namespace std;
void print_eth_hdr(struct eth_hdr *hdr)
{

    std::string dest;
    std::string src;
    std::string aux;
    dest = mac_from_arr(hdr->dmac);
    src = mac_from_arr(hdr->smac);

    cout<<"############## ETHERNET ################\n";

    std::cout << "dest: " + dest + " src: " + src << '\n';
    switch (hdr->ethertype) {
    case ETH_P_ARP:
        break;
    case ETH_P_IP:
        break;
    case ETH_P_IPV6:
        break;
    default:
        std::cout << ("unknown frame type\n");
    }
}

void handle_ether_hdr(struct eth_hdr *hdr)
{
    switch (hdr->ethertype) {
    case ETH_P_ARP:
        handle_ARP(hdr);
        break;
    case ETH_P_IP:
        handle_ip((struct ip_hdr*) hdr->payload);
        break;

    default:
        return;
    }
}
