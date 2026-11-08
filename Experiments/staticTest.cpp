#include <iostream>
#include <vector>

/**
 * @brief Class designed to contain an Id that program auto increments for each aditional instance 
 * using a static int property for the class
 */
class Test {
    public:
        Test();
        int GetId();
        
    private:
        static int NextId; // Any of the instances of Test can access this and it will be the same for all of them
        int Id;
};

Test::Test() {
    Id = NextId;
    NextId++;
}

int Test::GetId() {
    return Id;
}

// Initializes static property when program executes
int Test::NextId = 0;

int main() {
    std::vector<Test> tests(10);
    for(auto test : tests)
        std::cout << test.GetId(); 
    return 0;
}