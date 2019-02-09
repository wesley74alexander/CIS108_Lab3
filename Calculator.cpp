//Defines functions to be used in Main.cpp
#include "Calculator.h"
#include <math.h> //contains pow() function
#include <string>

namespace cal{

double num1;
double num2;
double stored;
std::string build_num1;
std::string build_num2;
bool first_entry;

double add(double num1, double num2){
  return num1 + num2;
};
double subtract(double num1, double num2){
  return num1 - num2;
};
double multiply(double num1, double num2){
  return num1 * num2;
};
double divide(double num1, double num2){
  return num1 / num2;
};
double power(double num1, double num2){
  return pow(num1, num2); //from math.h since std library does not include exponentiation function
};
double store(double num1){
  stored = num1;
  return stored;
};
double recallmem(double stored){
  return stored;
};
double clearmem(double stored){
  stored = 0.0;
  return stored;
};
double invert(double num1){
  num1 *= -1;
  return num1;
};
double clearval(double num1, double num2, std::string build_num1, std::string build_num2, bool first_entry){
  num1 = 0.0;
  num2 = 0.0;
  build_num1 = "";
  build_num2 = "";
  first_entry = true;
  return num1;
};
}
