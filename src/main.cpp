#include <iostream>

#include "main.hpp"

struct Object {
	std::string str;
	Object( std::string s ) : str( s ) {}
	// ~Object() = default; // this will delete move semantics implicitly
};

template<typename T>
void do_something( T && );
// void do_something( const Object & );
// void do_something( Object & );
// void do_something( Object && );
void inner_function( const Object & );
void inner_function( Object & );
void inner_function( Object && );

int main()
{
	const Object obj1{ "object1" };
	Object obj2 = obj1; // Copy constructor

	obj2.str = "object2";
	std::cout << obj1.str << std::endl;
	std::cout << obj2.str << std::endl;

	do_something( obj1 );
	do_something( obj2 );
	do_something( Object( "unnamed object" ) );

	return 0;
}

template<typename T>
void do_something( T &&var ) {
	inner_function( std::forward<T>( var ) ); // this will preserve rvalue semantic to keep it from turning into an lvalue because var is a named param
}

// void do_something( const Object &var ) {
// 	inner_function( var );
// }
// void do_something( Object &var ) {
// 	inner_function( var );
// }
// void do_something( Object &&var ) {
// 	inner_function( std::move(var) );
// }

void inner_function( const Object &obj ) {
	std::cout << "const Object&\n";
	std::cout << obj.str << std::endl;
}
void inner_function( Object &obj ) {
	std::cout << "Object&\n";
	std::cout << obj.str << std::endl;
}
void inner_function( Object &&obj ) {
	std::cout << "Object&&\n";
	std::cout << obj.str << std::endl;
}

