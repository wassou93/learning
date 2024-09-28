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

template <typename Container>
void print_iterator_type() {
	using IteratorType = std::ranges::iterator_t<Container>;
	using ValueType1 = std::ranges::range_value_t<Container>;
	using ValueType2 = Container::value_type;
	std::cout << "Iterator type: " << typeid( IteratorType ).name() << std::endl;
	std::cout << "Value type 1: " << typeid( ValueType1 ).name() << std::endl;
	std::cout << "Value type 2: " << typeid( ValueType2 ).name() << std::endl;
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
	std::copy_if( a.begin(), a.end(), std::inserter( uppers, uppers.begin() ), std::isupper );
	// we use uppers.end() here to not override the previous a string data
	std::copy_if( b.begin(), b.end(), std::inserter( uppers, uppers.end() ), std::isupper );

	// an easier way is to just use std::back_inserter to grow and return the last placeholder always
	// very similar to how push_back does the insertion
	// std::copy_if( a.begin(), a.end(), std::back_inserter( uppers ), std::isupper );
	// std::copy_if( b.begin(), b.end(), std::back_inserter( uppers ), std::isupper );

	// In the std::inserter example we used something called trait type std::ranges::iterator_t<Container>
	// This is used in metaprogramming to get the iterator type of the container

	// Write result
	write_to_cout( uppers );
	std::cout << std::endl;

	// ex: std::ranges::iterator_t<Container>
	print_iterator_type<decltype( uppers )>();
	// Iterator type: class std::_String_iterator<class std::_String_val<struct std::_Simple_types<char> > >
	print_iterator_type<std::vector<int>>();
	// Iterator type : class std::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<int> > >

	// I have added also two methods of getting the value type using trait types
	// Iterator type : class std::_String_iterator<class std::_String_val<struct std::_Simple_types<char> > >
	// Value type 1 : char
	// Value type 2 : char
	// Iterator type : class std::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<int> > >
	// Value type 1 : int
	// Value type 2 : int

	std::cin.get();
}
