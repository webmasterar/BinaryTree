//license MIT Ahmad Retha 2016

#ifndef __BINARYTREE__
#define __BINARYTREE__

#include <stdbool.h>

#define fnCount(a) ( sizeof(a) / sizeof((a)[0]) )

struct Node {
	int data;
	struct Node * left;
	struct Node * right;
};

void insert ( struct Node ** nodePtr, int value );
bool lookup ( struct Node ** nodePtr, int value );
void delete ( struct Node ** nodePtr, int value );
void destroy ( struct Node ** nodePtr );

#endif
