#include <iostream>
#include <string>

int main() {
    int x = 1;
    int* y = &x;
    int& z = *y;
    int& a = x;
    int* b = &a;

    std::string address = "[Memory Address] "; 
    std::string value   = "[Value Stored]   ";

    std::cout << address << "x: " << &x << '\n';
    std::cout << value   << "x: " << x  << '\n';
    std::cout << address << "y: " << &y << '\n';
    std::cout << value   << "y: " << y  <<  "or" << *b << '\n';
    std::cout << address << "z: " << &z << '\n';
    std::cout << value   << "z: " << z  << '\n';
    std::cout << address << "a: " << &a << '\n';
    std::cout << value   << "a: " << a  << '\n';
    std::cout << address << "b: " << &b << '\n';
    std::cout << value   << "b: " << b  <<  "or" << *b << '\n';

    std::cout << "\n\nUpdating value of x\n\n"; 
    x++;

    std::cout << address << "x: " << &x << '\n';
    std::cout << value   << "x: " << x  << '\n';
    std::cout << address << "y: " << &y << '\n';
    std::cout << value   << "y: " << y  << "or" << *b << '\n';
    std::cout << address << "z: " << &z << '\n';
    std::cout << value   << "z: " << z  << '\n';
    std::cout << address << "a: " << &a << '\n';
    std::cout << value   << "a: " << a  << '\n';
    std::cout << address << "b: " << &b << '\n';
    std::cout << value   << "b: " << b  << "or" << *b << '\n';
}