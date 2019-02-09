//Declares funtion prototypes and variables
#include <string>
#pragma once
namespace cal{
  double add(double, double);
  double subtract(double, double);
  double multiply(double, double);
  double divide(double, double);
  double power(double, double);
  double store(double);
  double clearmem(double);
  double recallmem(double);
  double invert(double);
  double clearval(double, double, std::string, std::string, bool);
}
