#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdbool.h>
#include <string.h>

char *get_mem(int pid)
{
char pidstr[10];
char runcmd[100]="/proc/";
snprintf(pidstr,sizeof(pidstr),"%d",pid);
strcat(runcmd,pidstr);
strcat(runcmd,"/maps");
// For now r later can do w to write to it aswell
FILE *memMap=fopen(runcmd,"r");
char line[512];
// Formatting and scanning the region of the memory:
long start;
long end;
char permissions[5];

printf("Press any key to start");
while(fgets(line,sizeof(line),memMap))
{
// Get each line then store the start, end and permissions from the line into their own separate vars

scanf(line,"%lx-%lx %4s",&start,&end,permissions);
printf("Start: %lx \n",start);
printf("End: %lx \n",end);
printf("Perms: %s\n\n",permissions);

}
return "h";
}

int main()
{
get_mem(7724);
return 0;
}
