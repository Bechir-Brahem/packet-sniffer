#include "arp.h"
using namespace std;
/**
 * @brief prints an arp header
 *
 * @param arp
 * @param arp_ip
 */
void print_arp(struct arp_hdr *arp, struct arp_ip_hdr *arp_ip)
{
    cout << "############## ARP  #################" << '\n';
    cout << "hardware address type " << hex << arp->hrd <<dec<< ' ';
    cout << "protocol type " << hex << arp->pro <<dec<< '\n';
    cout << "hardware address size " << (int)arp->hln << ' ';
    cout << "protocol address " << (int)arp->pln << ' ';
    cout << "ARP op code " << arp->op << '\n';
    cout << "=====================================" << '\n';
    cout << "sender mac address " << mac_from_arr(arp_ip->smac) << '\n';
    cout << "sender ip address " << ip_from_arr(arp_ip->sip) << '\n';
    cout << "target mac address " << mac_from_arr(arp_ip->dmac) << '\n';
    cout << "target ip address " << ip_from_arr(arp_ip->dip) << '\n';
    cout << "=====================================" << '\n';
    cout << endl;
}


void handle_ARP(struct eth_hdr *hdr)
{
    auto *arp = (struct arp_hdr *)hdr->payload;
     arp->hrd = ntohs(arp->hrd);
     arp->pro = ntohs(arp->pro);
     arp->op = ntohs(arp->op);
    auto *arp_ip = (struct arp_ip_hdr *)arp->data;
    print_arp(arp, arp_ip);

}
