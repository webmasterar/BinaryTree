//license MIT Ahmad Retha 2016

#include <stdio.h>
#include <stdbool.h>
#include "binarytree.h"

int main ()
{
	printf ( "# Staring tests\n" );
	
	struct Node * tree = NULL;
	int nums[] = {5, 3, 7, 4, 6, 2};
	int i, c = fnCount ( nums );

	printf ( "# Test: insert numbers\n" );
	
	// insert numbers into binary tree
	for ( i = 0; i < c; i++ )
	{
		printf ( "Inserted %d\n", nums[i] );
		insert ( &tree, nums[i] );
	}

	printf ( "# Test: remove 3 and sub-children\n" );
	
	// remove one of the numbers
	delete ( &tree, 3 );

	printf ( "# Test: checking numbers originally inserted still exist\n" );
	
	// check the numbers all exist in the tree
	for ( i = 0; i < c; i++ )
	{
		if ( lookup ( &tree, nums[i] ) )
		{
			printf ( "Found %d\n", nums[i] );
		}
		else
		{
			printf ( "%d not found\n", nums[i] );
		}
	}

	printf ( "# Test: destroy tree to free memory\n" );

	//clean up
	destroy ( &tree );
	
	printf ( "# Tests complete\n" );

	return 0;
}
