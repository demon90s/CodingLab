#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    #include <sys/socket.h>
    #include <netdb.h>

    void getaddrinfo(const char* host,
                     const char* service,
                     const struct addrinfo *hint,
                     struct addrinfo **res);

    将主机名和一个服务名映射到一个 addrinfo 结构。它包含了这个服务的相关信息（结果放到res，是一个链表）。

    hint是一个filter。
*/

// type: ./getaddrinfo localhost nfs

#define err_quit(fmt, ...)\
{\
    fprintf(stderr, fmt, ##__VA_ARGS__);\
    exit(1);\
}

void print_family(struct addrinfo *aip)
{
    printf(" family ");
    switch(aip->ai_family) {
        case AF_INET:
            printf("inet");
            break;
        case AF_INET6:
            printf("inet6");
            break;
        case AF_UNIX:
            printf("unix");
            break;
        case AF_UNSPEC:
            printf("unspecified");
            break;
        default:
            printf("unknown");
    }
}

void print_type(struct addrinfo *aip)
{
    printf(" type ");
    switch(aip->ai_socktype) {
        case SOCK_STREAM:
            printf("stream");
            break;
        case SOCK_DGRAM:
            printf("datagram");
            break;
        case SOCK_SEQPACKET:
            printf("seqpacket");
            break;
        case SOCK_RAW:
            printf("raw");
            break;
        default:
            printf("unknown (%d)", aip->ai_socktype);
    }
}

void print_protocol(struct addrinfo *aip)
{
    printf(" protocol ");
    switch(aip->ai_protocol) {
        case 0:
            printf("default");
            break;
        case IPPROTO_TCP:
            printf("tcp");
            break;
        case IPPROTO_UDP:
            printf("udp");
            break;
        case IPPROTO_RAW:
            printf("raw");
            break;
        default:
            printf("unknown (%d)", aip->ai_protocol);
    }
}

int main(int argc, char* argv[])
{
    if (argc < 3)
        err_quit("usage: %s nodename service\n", argv[0]);

    struct addrinfo hint;
    memset(&hint, 0, sizeof(hint));
    hint.ai_flags = AI_CANONNAME; // 表示需要一个规范的名字（与别名相对）

    int err;
    struct addrinfo *ailist;
    if ((err = getaddrinfo(argv[1], argv[2], &hint, &ailist)) != 0)
        err_quit("getaddrinfo error: %s\n", gai_strerror(err)); // 错误信息必须这样获取

    struct addrinfo *aip;
    for (aip = ailist; aip != NULL; aip = aip->ai_next)
    {
        print_family(aip);
        print_type(aip);
        print_protocol(aip);
        printf("\n");

        if (aip->ai_family == AF_INET)
        {
            char abuf[INET_ADDRSTRLEN];

            struct sockaddr_in *sinp = (struct sockaddr_in*)aip->ai_addr;
            const char* addr = inet_ntop(AF_INET, &sinp->sin_addr, abuf, INET_ADDRSTRLEN);
            printf(" address %s", addr ? addr : "unkown");
            printf(" port %d", ntohs(sinp->sin_port));
        }

        printf("\n");
    }
}