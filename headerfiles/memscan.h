
#ifndef MEMSCAN_H
#define MEMSCAN_H
#include <stdbool.h>
#define MAX_ADDRS 10000
struct result {
	unsigned long addr[MAX_ADDRS];
	int value;
	bool check;
};
struct result memScan(int pidx,int target);
#endif
