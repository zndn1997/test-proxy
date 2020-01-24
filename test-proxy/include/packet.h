#ifndef PROXY_INCLUDE_PACKET_H_
#define PROXY_INCLUDE_PACKET_H_

#include <netinet/ip.h>
#include <linux/in.h>
#include <linux/tcp.h>
#include <sys/types.h>

enum packet_addr_change_type
{
	PACKET_ADDR_CHANGE_TYPE_SOURCE,
	PACKET_ADDR_CHANGE_TYPE_DEST
};

enum packet_error_type
{
	PACKET_SUCCESS,
	PACKET_INVALID,
	PACKET_ALLOC_FAILED
};

/* TCP Pseudo header */
struct pseudohdr
{
	u_int32_t saddr;		/* Source IP */
    u_int32_t daddr;		/* Destination IP */
    u_int8_t useless;		/* Unused */
    u_int8_t protocol;		/* Protocol type */
    u_int16_t tcplength;	/* TCP Header size */
};

/* TCP Header information use to calculate checksum */
struct tcpcksumhdr
{
	struct pseudohdr pseudo_header;
	struct tcphdr tcp_header;
};

void change_packet_address(unsigned char* target_packet, const struct sockaddr_in* address, int change_type);
void calculate_tcp_header_cksum(struct tcphdr* dest_tcp_header, struct tcpcksumhdr* master_header, const struct iphdr* source_ip_header, int ip_header_length);
unsigned short in_cksum(unsigned short* addr, int len);

#endif

