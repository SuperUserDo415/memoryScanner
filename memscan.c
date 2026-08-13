
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include <unistd.h>

int main(int argCount,char *argVars[])
{
    char line[256];
    char pidc[20];
    int pidx=atoi(argVars[1]);

    if(argCount<3)
    {
        printf("Run with correct parameters plz \n");
        printf("->EXAMPLE USAGE<- \n ./memscan.out [PID] [TARGET VALUE] \n");
    }

    sprintf(pidc,"%d",pidx);
    char runcmd[100] = "/proc/";
    char perms[5];

    strcat(runcmd, pidc);
    strcat(runcmd, "/maps");

    pid_t pid = pidx;
    int target = atoi(argVars[2]);

    printf("Looking for: %d \n",target);

    // Start and end address for scanning region
    uintptr_t start;
    uintptr_t end;

    // Size (end - start)
    size_t size;

    // Contains address and size of memory for local
    // (destination of memory put from remote)
    struct iovec local;
    struct iovec remote;

    // Open target's memory map
    FILE *mem = fopen(runcmd, "r");

    if(mem==NULL)
    {
        printf("ERROR: Process may not be running or you entered the wrong PID \n");
        return -1;
    }

    // Read memory map one at a time
    while (fgets(line, sizeof(line), mem))
    {
        // Extract start and end addresses
        // Also permissions (not working currently)
        sscanf(line, "%lx-%lx", &start, &end);

        //printf("Region: %lx - %lx\n", start, end);

        size = end - start;

        // Make buffer for this region
        unsigned char *buffer = malloc(size);

        local.iov_base = buffer;
        local.iov_len = size;

        remote.iov_base = (void *)start;
        remote.iov_len = size;

        // Copy target memory into buffer
        ssize_t nread = process_vm_readv(
            pid,
            &local,
            1,
            &remote,
            1,
            0
        );

        //printf("Read %zd bytes\n", nread);

        // ERROR condition is wrong, sort of fix later
        if(nread==-1)
        {
            //printf("ERROR: Operation not permitted ( Try running with sudo )");
            //return -1;
        }

        if (nread > 0)
        {
            // Look through the copied bytes
            for (size_t i = 0;
                 (i + sizeof(int)) <= ((size_t)nread);
                 i++)
            {
                int value;

                // 4 Bytes means int
                memcpy(&value, buffer + i, sizeof(int));

                if (value == target)
                {
                    printf("Found %d \n", target);
                    printf("Address: %lx \n", (start + i));
		    // Save to struct
		    /*
		    s->val=target;
		    s->addr=(start+i);
*/
		    //return 0;
                }
            }
        }
    }
}
