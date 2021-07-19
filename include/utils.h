//
// Created by bb on 7/13/21.
//

#ifndef UTILS_H
#define UTILS_H

#include<iostream>
extern int tun_fd;

void parse_mac(unsigned char* bytes, std::string const& in) ;
void parse_ip(unsigned char* bytes, std::string const& in) ;
std::string mac_from_arr(unsigned char *t);
std::string ip_from_arr(unsigned char *t);
#endif //UTILS_H
