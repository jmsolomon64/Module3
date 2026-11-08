#include <string>
class FoodItem {
    public:
        FoodItem();
        FoodItem(double fat, double carbs, double protein);
        std::string GetName();
        double GetFat();
        void   SetFat(double fat);
        double GetCarbs();
        void   SetCarbs(double carbs);
        double GetProtein();
        void   SetProtein(double protein);
        double GetCalories(double numServings);
        void PrintInfo();
    private:
        std::string name;
        double fat;
        double carbs;
        double protein;
};