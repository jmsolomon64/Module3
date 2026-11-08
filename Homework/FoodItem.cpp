#include "./FoodItem.h"
#include <iostream>
#include <iomanip> 

using namespace std;

FoodItem::FoodItem() {}

FoodItem::FoodItem(double fat, double carbs, double protein) {
   this->fat = fat;
   this->carbs = carbs;
   this->protein = protein;
}

string FoodItem::GetName() {
   return name;
}

double FoodItem::GetFat() {
   return fat;
}

void FoodItem::SetFat(double fat) {
   this->fat = fat;
}

double FoodItem::GetCarbs() {
   return carbs;
}

void FoodItem::SetCarbs(double carbs) {
   this->carbs = carbs;
}

double FoodItem::GetProtein() {
   return protein;
}

void FoodItem::SetProtein(double protein) {
   this->protein = protein;
}

double FoodItem::GetCalories(double numServings) {
   // Calorie formula
   double calories = ((fat * 9) + (carbs * 4) + (protein * 4)) * numServings;
   return calories;
}

void FoodItem::PrintInfo() {
   cout << fixed << setprecision(2);
   cout << "Nutritional information per serving of " << name  << ":" << endl;
   cout << "  Fat: " << fat << " g" << endl;
   cout << "  Carbohydrates: " << carbs << " g" << endl;
   cout << "  Protein: " << protein << " g" << endl;
}

int main() {
   FoodItem food(1, 2, 3);
   if(food.GetFat() != 1) 
      cout << "Failed GetFat() test with param constructor" << endl;
   if(food.GetCarbs() != 2) 
      cout << "Failed GetCarbs() test with param constructor" << endl;
   if(food.GetProtein() != 3) 
      cout << "Failed GetProtein() test with param constructor" << endl;
   if(food.GetCalories(1) != 29)
      cout << "Failed GetCalories() test with param constructor" << endl;
   food.PrintInfo();

   FoodItem food1;
   food1.SetFat(1);
   if(food1.GetFat() != 1) 
      cout << "Failed GetFat() test with set method" << endl;
   food1.SetCarbs(2);
   if(food1.GetCarbs() != 2) 
      cout << "Failed GetCarbs() test with set method" << endl;
   food1.SetProtein(3);
   if(food1.GetProtein() != 3) 
      cout << "Failed GetProtein() test with set method" << endl;
   if(food1.GetCalories(1) != 29)
      cout << "Failed GetCalories() test with set method" << endl;
}