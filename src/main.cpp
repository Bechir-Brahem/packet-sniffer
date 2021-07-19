#include <iostream>
using namespace std;
#include "ethernet.h"
int tun_fd=0;
int main()
{
    char buffer[500];

    tun_fd= socket(AF_PACKET,SOCK_RAW,htons(ETH_P_ALL));

    if (tun_fd < 0)
    {
        perror("Allocating interfacaaae");
        exit(1);
    }

    /* Now read data coming from the kernel */
    while (true)
    {
        /* Note that "buffer" should be at least the MTU size of the interface,
         * eg 1500 bytes */
        int nread = read(tun_fd, buffer, sizeof(buffer));
        if (nread < 0)
        {
            perror("Reading from interface");
            close(tun_fd);
            exit(1);
        }
        auto *hdr = (struct eth_hdr *)buffer;
        hdr->ethertype = ntohs(hdr->ethertype);
        print_eth_hdr(hdr);
        handle_ether_hdr(hdr);
    }
}
