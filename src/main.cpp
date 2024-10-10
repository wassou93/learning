#include <stdio.h>
#include <stdlib.h>

#include "main.hpp"

int main()
{
	int *num_ptr = ( int * ) malloc( sizeof( int ) );

	if ( num_ptr == NULL )
	{
		fprintf( stderr, "Value was not allocated correctly!" );
		return 1;
	}

	*num_ptr = 24;

	printf( "%d\n", *num_ptr );

	free( num_ptr );

	return 0;
}

