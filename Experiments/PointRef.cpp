


#include <iostream>
void add(int *x, int y) {
    x += y;
}

void add1(int &x, int y) {
    x += y;
}

int main(int argc, char** argv) {
    int x = 1;
    int y = 2;

    std::cout << "x before any operation" << x << '\n';
    add1(x, y);
    std::cout << "x after add with reference" << x << '\n';
    add(&x, y);
    std::cout << "x after add with reference" << x << '\n';

    int* z = &x; // Pointer initialization uses reference to assign to since reference is mem address
    int& a = y;
    z = &y;
    a = y;

    std::cout << "z:" << z << '\n';
    std::cout << "y:" << &y << '\n';

    // Pointers can be referenced by var name only, which appears to display address pointer is pointing to
    // can be referenced with &varname which appears to display memory address of pointer
    // can be referenced with *varname which appears to display value from memory address it points to
    std::cout << "z:" << z << '\n';
    std::cout << "&z:" << &z << '\n';
    std::cout << "*z:" << *z << '\n'; 
    std::cout << "a:" << a << '\n';
    std::cout << "&a:" << &a << '\n';
    std::cout << "*a is invalid"  << '\n';
    
    // *z = *z + y; //Proper way to do arithmetic with pointers
    //since y is 1 this will actually make it move one memory address over which is the memory address of z
    z = z + y; //This will do arithmetic on the memory address which causes result to be diff each run (I think)
    std::cout << "z:" << z << '\n';
    
    a = a + y;
    std::cout << "a:" << a  << '\n';
    std::cout << "*z:" << *z  << '\n'; 

}