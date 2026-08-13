
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include <unistd.h>

int cMem(pid_t pid,long addr,int val)
{
// Given: pid,addr,new value
// Program flow: make new local's value to our new value ( int val )
// Copy the local iovec's buffer to the remote iovec's buffer ( Writing it using process_vm_writev
struct iovec local={
.iov_base=&val,
.iov_len=sizeof(val)
};
struct iovec remote={
.iov_base=(void *)addr,
.iov_len=sizeof(val)
};
// Write 
ssize_t written=process_vm_writev(pid,&local,1,&remote,1,0);
if(written==-1)
{
printf("ERROR: can't write");
return -1;
}
printf("Wrote %zd bytes: \n ",written);
int confVal;
local.iov_base=&confVal;

process_vm_readv(pid,&local,1,&remote,1,0);

printf("Value of address: %d",confVal);

}
/*
int main(int argCount,char *argVar[])
{
if(argCount!=4)
{
printf("Error wrong number of arguments provided");
return -1;
}
int pid=atoi(argVar[1]);
long addr=strtol(argVar[2],NULL,16);
int val=atoi(argVar[3]);
printf("PID:[%d],ADDRESS:[0x%lx],NEWVALUE:[%d] \n",pid,addr,val);
pid_t pidt=(pid_t)pid;
cMem(pidt,addr,val);
return 0;
}
*/
