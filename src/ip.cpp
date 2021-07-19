//
// Created by bb on 7/14/21.
//

#include "ip.h"


using namespace std;

void print_ip(struct ip_hdr* ip)
{



    cout<<"############## IPv4 ################\n";
    cout<<"version: "<<hex<<(int) ip->version<<dec<<' ';
    cout<<"ihl: "<<(int) ip->ihl<<' ';
    cout<<"tos: "<<(int) ip->tos<<' ';
    cout<<"tot_len: "<<(int) ntohs(ip->tot_len)<<' ';
    cout<<"id: "<<hex<<(int) ntohs(ip->id)<<dec<<'\n';
    cout<<"flag + frag_offset: 0x"<<hex<<ntohs(ip->frag_off)<<dec<<' ';//byte order problem
    cout<<"TTL: "<<(int) ip->ttl<<' ';
    if((int)ip->protocol==IPPROTO_ICMP)
//    cout<<"protocol: ICMP\n";
        ;
    else if (ip->protocol==IPPROTO_TCP)
        cout<<"protocol: TCP\n";
    else if(ip->protocol==IPPROTO_UDP)
        cout<<"protocol: UDP\n";
    else
        cout<<"unknown protocol: "<<(int) ip->protocol<<'\n';
    cout<<"checksum: "<<hex<<(int) ntohs(ip->check)<<dec<<' ';
    uint16_t tmp=ip->check;
    ip->check=0;
    if(tmp==checksum((uint16_t *)ip,(size_t) ip->ihl*2))
    {
        cout<<"[ checksum valid ]\n";
    }
    else
        cout<<"[ checksum invalid ]\n";
    cout<<"source: "<<ip_from_arr(ip->saddr)<<' ';
    cout<<"dest: "<<ip_from_arr(ip->daddr)<<'\n'<<endl;


}

void handle_ip(struct ip_hdr* ip)
{
    print_ip(ip);
    switch (ip->protocol) {
        case IPPROTO_ICMP:
            handle_icmp((struct icmp_hdr*)ip->data,(size_t) ip->tot_len-ip->ihl*4);
            break;

    }




}

uint16_t checksum(uint16_t* ptr,size_t size){
    uint32_t ret=0;
    uint32_t tmp=1<<16;
    while(size){
        ret+=*ptr;
        ptr++;
        size--;
        if((ret & tmp) !=0)
        {
            ret-=tmp;
            ret++;
        }
    }
    return (uint16_t )~ret;
}
