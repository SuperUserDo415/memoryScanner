#include <stdio.h>
#include <unistd.h>
int main()
{
unsigned long x=4122322;
printf("PID: %d \n ", getpid());
printf("Enter value of x-> ");
scanf("%ld",&x);

while(1)
{
// Print original value in a loop
printf("Value of x: %ld \n",x);
sleep(1);
}
return 0;
}
//
