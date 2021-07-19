//
// Created by bb on 7/15/21.
//
#include"icmp.h"


using namespace std;
void print_icmp(struct icmp_hdr* icmp)
{
    cout<<"############## ICMP ################\n";
    cout<<"type: "<<(int)icmp->type<<'\n';
    cout<<"code: "<<(int)icmp->code<<'\n';
    cout<<"csum: "<<hex<<ntohs(icmp->csum)<<dec<<endl;
}
void handle_icmp(struct icmp_hdr* icmp,size_t icmp_size)
{
    print_icmp(icmp);
    if(icmp->type==ICMP_ECHO_REQ)
    {
        print_icmp_echo((struct icmp_echo*) icmp->data,"ECHO REQ");
    }
    else if(icmp->type==ICMP_ECHO_REP)
    {
        print_icmp_echo((struct icmp_echo*) icmp->data,"ECHO REP");

    }


}


void print_icmp_echo(icmp_echo *icmp,string a) {
    cout<<"############## "<<a<<" ################\n";
    cout<<"id: "<<icmp->id;
    cout<<"\nseq: "<<icmp->seq<<'\n'<<endl;
}
