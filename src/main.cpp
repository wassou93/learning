#include <iostream>

#include "main.hpp"

int main()
{
	int *num_ptr = nullptr;

	try
	{
		num_ptr = new int;

		*num_ptr = 42;
		std::cout << "Dynamic number: " << *num_ptr << std::endl;
	}
	catch ( const std::bad_alloc& e )
	{
		std::cout << "Allocation Error: " << e.what() << std::endl;
		return 1;
	}

	delete num_ptr;

	return 0;
}

