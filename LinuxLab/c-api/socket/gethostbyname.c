/*
	#include <netdb.h>

	struct hostent *gethostbyname(const char *name);

	根据主机名返回主机数据库
	struct hostent 至少包含：

	struct hostent {
		char *h_name;		// name of the host
		char **h_aliases;	// list of aliase (nicknames)
		int h_addrtype;		// address type
		int h_length;		// length in bytes of the address
		char **h_addr_list;	// list of address(network order)
	};

	失败返回空指针。

	Note:
	由于获得的地址是网络字节序，所以要用 inet_ntoa 将网络字节序转换为可打印的字符串。

*/

#include <unistd.h>
#include <arpa/inet.h>	// for inet_ntoa
#include <netdb.h>
#include <assert.h>
#include <stdio.h>

void test1()
{
		char hostname[255];
	gethostname(hostname, sizeof(hostname));

	struct hostent *he = gethostbyname(hostname);
	if (he == NULL) {
		fprintf(stderr, "gethostbyname failed\n");
		return;
	}

	// print host data
	printf("host ent is:\n");
	printf("------------\n");
	
	printf("name of the host: %s\n", he->h_name);
	
	printf("list of aliase:");
	{
		char **name = he->h_aliases;
		while (*name) {
			printf(" [%s]", *name);
			name++;
		}
		printf("\n");
	}
	
	printf("address type is AF_INET? %s\n", he->h_addrtype == AF_INET ? "yes" : "no");
	assert(he->h_addrtype == AF_INET); // 下面强制转换依赖于此

	printf("list of ip:");
	{
		char **addr = he->h_addr_list;
		while (*addr) {
			printf(" [%s]", inet_ntoa(*(struct in_addr*)*addr));
			addr++;
		}
		printf("\n");
	}
}

int connect_to_server(const char *server, short port)
{
	int hSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (hSocket == -1)
		return -1;

	struct sockaddr_in addrSrv = { 0 };
	struct hostent *pHostent = NULL;

	// 如果传入的参数 server 的值是 somesite.com 这种域名形式，则 if 条件成立
	if ((addrSrv.sin_addr.s_addr = inet_addr(server)) == INADDR_NONE)
	{
		// 接着调用 gethostbyname 将十进制点分法 IP 地址解析成4字节的整型数值
		pHostent = gethostbyname(server);
		if (NULL == pHostent)
			return -1;

		// 使用 gethostyname 解析域名时可能会得到多个IP地址，常使用第1个IP
		addrSrv.sin_addr.s_addr = *((unsigned long *)pHostent->h_addr_list[0]);
	}

	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(port);
	int ret = connect(hSocket, (struct sockaddr *)&addrSrv, sizeof(addrSrv));
	if (ret == -1)
		return -1;

	return 0;
}

void test2()
{
	if (0 == connect_to_server("baidu.com", 80))
		printf("connect succ\n");
	else
		printf("connect fail\n");
}

int main()
{
	//test1();

	test2();

	return 0;
}
