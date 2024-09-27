#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator> // Include this header for std::ostream_iterator

#include "main.h"

template<typename Container>
void write_to_cout(const Container& container, const char* delimiter = " ")
{
    std::copy(container.begin(), container.end(),
        std::ostream_iterator<typename Container::value_type>(std::cout, delimiter));
}

int main()
{
    std::vector<std::string> a = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };
    std::vector<std::string> b = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };

    // write initial states
    write_to_cout(a);
    std::cout << std::endl;
    write_to_cout(b);
    std::cout << std::endl << std::endl;

    // test algorithm
    std::copy_n(b.begin(), 4, b.begin() + 6); // changing function to copy_n and use number of hopes instead of end iterator
    write_to_cout(b);

    std::cout << std::endl;

    std::cout << typeid(std::vector<std::string>::value_type).name() << std::endl;

    // If you want to read from input stream
    // You cannot give iterator + x with std::copy 
    // so you have to use std::copy_n instead to read a number of chars

    std::copy_n(std::istream_iterator<std::string>(std::cin), 5, b.begin());
    std::cout << std::endl;
    write_to_cout(b);
    std::cout << std::endl;

    std::vector<std::string> bf = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };

    std::copy_backward(bf.begin() + 1, bf.begin() + 3, bf.begin() + 2); // when you overlapping copy ranges in the same contiguous container
    // You can achieve the same affect by using rbegin and rend which renders copy_backward as redudant 
    
    std::cout << std::endl;
    write_to_cout(bf);
    std::cout << std::endl;

    std::vector<std::string> br = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };
    std::copy(br.rbegin() + 1, br.rbegin() + 3, br.rbegin() + 2); // when you overlapping copy ranges in the same contiguous container
    // You can achieve the same affect by using rbegin and rend which renders copy_backward as redudant 
    
    std::cout << std::endl;
    write_to_cout(br);
    std::cout << std::endl;

    std::cin.get();
}
