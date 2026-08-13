
#define _GNU_SOURCE
#include "../headerfiles/memscan.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include <unistd.h>
// First function: Filtering through various values to get the desired address of the value
// Example, for health in game = 100, game might have a gazillion addresses with value = 100, then health goes down to 90 so out of those 100 filter out of those that are now 90. so on and so forth until its down to one value.
// Also return the value as a struct so i can easily use it in front end rendering.
// Struct should return an address list, and a value
/*
struct result{
unsigned long addrs[MAX_ADDRS];
int value;
}
*/
// pidInt,int value;
int main(int argsCount,char *argVars[])
{	
	if(argsCount!=3)
	{
		printf("USAGE: sudo ./filter.out [PID] [VALUE] \n");
		return -1;
	}
	int pidInt=atoi(argVars[1]);
	int value=atoi(argVars[2]);
	pid_t pid=(pid_t)pidInt;
	struct result scanResult=memScan(pidInt,value);

	if(scanResult.check == false)
	{
	printf("Scan failed \n");
	return -1;
	}
	
}
