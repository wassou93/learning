#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <concepts>

#include "main.hpp"

template<typename Container>
void write_to_cout( const Container &container, const char *delimiter = " " )
{
	std::copy( container.begin(), container.end(),
		std::ostream_iterator<typename Container::value_type>( std::cout, delimiter ) );
}

int main()
{
	// Init test containers
	std::vector<std::string> a =
	{
		"zero", "one", "two", "three", "four", "five", "six", "seven", "right", "nine", "ten"
	};
	std::vector<std::string> b =
	{
		"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"
	};

	// Write initial cases
	write_to_cout( a );
	std::cout << std::endl;
	write_to_cout( b );
	std::cout << std::endl;
	std::cout << std::endl;

	// Test algorithm
	// std::move( a.begin(), a.begin() + 3, b.begin() );

	// Move if - we use move iters with copy_if
	std::copy_if( std::make_move_iterator( a.begin() ), std::make_move_iterator( a.end() ), b.begin(),
		[] ( const std::string &str ) {return str.size() > 3; } );

	// Write result
	write_to_cout( a, " | " );
	std::cout << std::endl;
	write_to_cout( b );


	std::cin.get();
}

