//
// Created by bb on 7/14/21.
//

#ifndef IP_H
#define IP_H

#include "utils.h"
#include <iostream>
#include "icmp.h"
#include <arpa/inet.h>
#include <cstring>
#include <ethernet.h>

struct ip_hdr
{
#if __BYTE_ORDER == __LITTLE_ENDIAN
    unsigned int ihl:4;
    unsigned int version:4;
#elif __BYTE_ORDER == __BIG_ENDIAN
    unsigned int version:4;
    unsigned int ihl:4;
#else
# error        "Please fix <bits/endian.h>"
#endif
    u_int8_t tos;
    u_int16_t tot_len;
    u_int16_t id;
    u_int16_t frag_off;
    u_int8_t ttl;
    u_int8_t protocol;
    u_int16_t check;
    unsigned char saddr[4];
    unsigned char daddr[4];
    unsigned char data[];
    /*The options start here. */
}__attribute((packed));



void handle_ip(struct ip_hdr*);
void print_ip(struct ip_hdr* ip);
uint16_t checksum(uint16_t* ptr,size_t size);
#endif //IP_H
