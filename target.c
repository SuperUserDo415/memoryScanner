#include <stdio.h>
#include <unistd.h>
int main()
{
int x=1234;
printf("PID: %d \n ", getpid());
printf("Value of x: %d \n",x);
while(1)
{
sleep(10);
}
return 0;
}
//
