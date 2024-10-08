#include <iostream>

#include "main.hpp"

int gcd( int, int );
bool is_prime( int );

int main()
{
	std::cout << "GCD of 123, 368 is: " << gcd( 128, 368 ) << std::endl;;
	std::cout << "123 is " << ( is_prime( 123 ) ? "a prime number" : "not a prime number." ) << std::endl;
	std::cout << "368 is " << ( is_prime( 368 ) ? "a prime number" : "not a prime number." ) << std::endl;
	return 0;
}

int gcd( int p, int q ) 
{
	if ( q == 0 ) return p;
	int r = p % q;
	return gcd( q, r );
}

bool is_prime( int n ) 
{
	if ( n <= 2 ) return n == 2;
	for ( size_t i{ 2 }; i <= ( size_t ) std::sqrt( n ); ++i )
	{
		if ( n % i == 0 ) return false;
	}
	return true;
}

