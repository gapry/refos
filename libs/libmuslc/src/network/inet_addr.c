/* @LICENSE(MUSLC_MIT) */

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "__dns.h"

in_addr_t inet_addr(const char *p)
{
	struct sockaddr_in sin;
	if (__ipparse(&sin, AF_INET, p)) return -1;
	return sin.sin_addr.s_addr;
}
