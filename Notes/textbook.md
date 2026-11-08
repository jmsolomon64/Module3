# Chapter 7
* Classes allow for a level of abstraction from the actual implementation
* Header files contain class definitions
* CPP files contain the actually definition of the logic for a class
    * CPP file must include header file for class it is making logic for
    * main function can be added at the end of this file to be used for testing purposes with the class
* Constructors allow for defining logic to run when object is constructed
    * Can have overloaded versions
    * If a constructor is made with params, a default one should be made or objects cannot be constructed without passing that param
        * can set it up so that params have default values which acts as default constructor
        * Initializer lists can be used in a constructor definition to set default values based on constructor being used
* Since objects are stored as pointers, to access a member of the class you must use the member access operator ->
* Operators can be overloaded for classes so that things like obj + obj actually does something 
    * Operators can be overloaded multiple times for a class to have operators that work with various data types
    * Equality operators require param for both left and right hand sides of the 
* Operator used with namespaces :: is called scope resolution operator
* static members are allocated in memory only once in program execution
    * when accessing a class's static member from outside the class using scope resolution operator 
        * ```ClassName::StaticMember ```
    * for static methods, static keyword is used in decleration of method but not in definition

```language=cpp

class Restaurant {                          // Keeps a user's review of a restaurant
   public:    
    Restaurant();                           // Constructor  
    Restaurant(int rating);                 // Overloaded Constructor
      void SetName(string restaurantName);  // Sets the restaurant's name        
      void SetRating(int userRating) {      // Inline method declaration
        rating = userRating;
      }  
      void Print();                         // Prints name and rating on one line 
      Restaurant operator+(Restaurant rhs);            // Operator overloading (rhs = right hand side)
   private:
      string name = "N/A";                  // Default Value
      int rating = -1;                      // Default Value
};

//Definitions of methods gooutside of the class itself like this
Restaurant::Restaurant() : name("N/A"), rating(-1) { // Initializer list 

}

Restaurant Restaurant::operator+(Restaurant rhs) {
    //body
}

Restaurant::SetName(string restaurantName) {
    name = restaurantName;
    this->SetRating(-1); // Member access operator
}

```