#include <stdio.h>
#define _GNU_SOURCE
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
int main()
{
	long int amma = syscall(546);
//	int tid = syscall(548);
//	printf("retur val: %d\n", tid);
//	printf("PID: %d\n", getpid());
	printf("System call sys_hello returned %ld\n", amma);
	return 0;
}
