//license MIT Ahmad Retha 2016

#include <stdlib.h>
#include <stdbool.h>
#include "binarytree.h"

void insert ( struct Node ** nodePtr, int value )
{
	if ( (* nodePtr) == NULL)
	{
		struct Node * node = ( struct Node * ) malloc ( sizeof ( struct Node ) );
		node->data  = value;
		node->left  = NULL;
		node->right = NULL;
		( * nodePtr ) = node;
		return;
	}

	if ( (* nodePtr)->data > value )
	{
		insert ( &(* nodePtr)->left, value );
	}
	else if ( (* nodePtr)->data < value )
	{
		insert ( &(* nodePtr)->right, value );
	}
}

bool lookup ( struct Node ** nodePtr, int value )
{
	if ( (* nodePtr) == NULL )
	{
		return false;
	}

	if ( (* nodePtr)->data == value )
	{
		return true;
	}

	if ( (* nodePtr)->data > value )
	{
		return lookup ( &(* nodePtr)->left, value );
	}
	else
	{
		return lookup ( &(* nodePtr)->right, value );
	}
}

void delete ( struct Node ** nodePtr, int value )
{
	if ( (* nodePtr) == NULL )
	{
		return;
	}

	if ( (* nodePtr)->data == value )
	{
		destroy ( nodePtr );
	}
	else
	{
		if ( (* nodePtr)->left != NULL )
		{
			delete ( &(* nodePtr)->left, value );
		}

		if ( (* nodePtr)->right != NULL )	
		{
			delete ( &(* nodePtr)->right, value );
		}
	}
}

void destroy ( struct Node ** nodePtr )
{
	if ( (* nodePtr)->left != NULL )
	{
		destroy ( &(* nodePtr)->left );
	}

	if ( (* nodePtr)->right != NULL )	
	{
		destroy ( &(* nodePtr)->right );
	}

	free ( (* nodePtr) );
	(* nodePtr) = NULL;
}
