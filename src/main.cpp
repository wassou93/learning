#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator> // Include this header for std::ostream_iterator

#include "main.h"

template<typename Container>
void write_to_cout( const Container &container, const char *delimiter = " " )
{
	std::copy( container.begin(), container.end(),
		std::ostream_iterator<typename Container::value_type>( std::cout, delimiter ) );
}

int main()

{
	// Init test containers 
	std::string a = "Happy Fun times With Capital letters";
	std::string b = "otHErwise KNOwn as upper CASE biotches";

	// Write initial states
	write_to_cout( a );
	std::cout << std::endl;
	write_to_cout( b );
	std::cout << std::endl;

	// test algorithm
	std::string uppers;
	// uppers.resize( a.length() + b.length() );
	// std::copy_if( a.begin(), a.end(), uppers.begin(), std::isupper );
	// std::copy_if( b.begin(), b.end(), uppers.begin() + 4, std::isupper );

	// Inserter is used to grow uppers if necessary and return an iterator of that placeholder
    // std::copy_if( a.begin(), a.end(), std::inserter(uppers, uppers.begin()), std::isupper);
	// we use uppers.end() here to not override the previous a string data
    // std::copy_if( b.begin(), b.end(), std::inserter(uppers, uppers.end()), std::isupper);

	// an easier way is to just use std::back_inserter to grow and return the last placeholder always
	// very similar to how push_back does the insertion
	std::copy_if( a.begin(), a.end(), std::back_inserter( uppers ), std::isupper );
	std::copy_if( b.begin(), b.end(), std::back_inserter( uppers ), std::isupper );

	// Write result
	write_to_cout( uppers );

	std::cin.get();
}
