#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdbool.h>
#include <string.h>

int main()
{
// For a specific program( in this case assaultcube)
/*
FILE *f = popen("pgrep -lf assaultcube | grep -o '[0-9]*' | head -n 1","r");
// Conversion:
int pid;
fscanf(f,"%d", &pid);

printf("The pid of assaultcube is: %d",pid);
printf("\n");
*/

// Get rows and columns of the terminal ( put in a loop for resizing )

int r,c;

// Printing all the pids and then let user select one of the process
initscr();
getmaxyx(stdscr,r,c);

printw("MEM SCANNER \n");
bool exit=false;
noecho();
nodelay(stdscr,TRUE);
FILE *pout = popen("pgrep -l . | grep -v kworker ","r");
char ch;
char line[250];
char sWord[50];
char *result;
int key;
// Display programs and their PIDs

refresh();
pclose(pout);
endwin();
return 0;
}

