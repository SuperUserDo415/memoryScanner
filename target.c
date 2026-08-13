#include <stdio.h>
#include <unistd.h>
int main()
{
unsigned long x=4122322;
printf("PID: %d \n ", getpid());

while(1)
{
scanf("%d",&x);
printf("Value of x: %d \n",x);
sleep(1);
}
return 0;
}
//
