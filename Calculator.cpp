//Defines functions to be used in Main.cpp
#include "Calculator.h"
#include <math.h> //contains pow() function
#include <string>

double current_value;
double memory_value;
double add(double a, double b){
  return a + b;
};
double subtract(double a, double b){
  return a - b;
};
double multiply(double a, double b){
  return a * b;
};
double divide(double a, double b){
  return a / b;
};
double power(double a, double b){
  return pow(a, b); //from math.h since std library does not include exponentiation function
};
void store(double current_value){
  memory_value = current_value;
};
double recallmem(){
  return memory_value;
};
void clearmem(){
  memory_value = 0.0;
};
double invert(double current_value){
  current_value *= -1;
  return current_value;
};
double clearval(){
  current_value = 0.0;
  return current_value;
};
