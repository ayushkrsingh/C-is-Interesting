#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
int main()
{
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	while(1) {
		// Some kind of req is received here---
		printf("waiting for request...\n");
		sleep(1);
	}

}
