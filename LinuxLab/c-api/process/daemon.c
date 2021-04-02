/*
	守护进程例子
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAXFILE 65535

// 使当前进程变成守护进程
void make_daemon()
{
	// step1: fork子进程，退出父进程，脱离shell
	pid_t pid = fork();
	if (pid < 0) {
		perror("fork");
		exit(1);
	}
	else if (pid > 0) {
		printf("daemon pid is: %d\n", pid);
		exit(0);
	}

	// step2: 创建新会话，将进程从原进程组独立
	setsid();

	// step3: 改变工作目录为根目录，避免某些特殊问题
	chdir("/");

	// step4: 重置文件权限掩码
	umask(0);
	
	// step5: 关闭已经打开了的文件描述符
	for (int i = 0; i < MAXFILE; i++) {
		close(i);
	}
}

int main()
{
	make_daemon();

	// do something background
	while (1) {
		int fd = open("/tmp/daemon.log", O_CREAT | O_WRONLY | O_APPEND, 0600);
		if (fd < 0) {
			exit(1);
		}

		char buffer[1024];
		time_t now = time(NULL);
		sprintf(buffer, "%s I am deamon process\n", ctime(&now));

		write(fd, buffer, strlen(buffer));
		close(fd);

		sleep(5);
	}

	return 0;
}
