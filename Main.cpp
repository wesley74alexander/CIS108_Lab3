#include <iostream>
#include <string>
#include "Calculator.h"

using namespace std;

double num1;
double num2;
bool first_entry = true;
char key;
char op;
string build_num1 = "";
string build_num2 = "";

int main()
{
  cout << "> ";
	do {
		key = getchar(); // Gets user input one character at a time
		switch (key) {
			case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '0': case '.':
				if (first_entry == true){ //
				      build_num1 += key; //Concatinates each successive character to build a string of the first number
				}
				else {
				      build_num2 += key;
				}
        break;
        case '+': case '-': case '*': case '/': case '^': //Selects which calculator function to perform based on user entered operation
          if(build_num1 != ""){
            num1 = stod(build_num1); //Converts string of the first number to a double ready for calculations
            build_num1 = "";
            build_num2 = "";
            first_entry = false;
            op = key;
            break;
          }
          else{
            cout << "Enter a number to begin" << endl << "> "; //Error message in the event that user enters operator before a entering a number
            break;
          }

        case 'c': case 'C':
          num1 = 0;
          num2 = 0;
          build_num1 = "";
          build_num2 = "";
          first_entry = true;
          break;
        case 's': case 'S':
          store(num1);
          cout << " Saved" << endl;
          break;
        case 'm': case 'M':
          clearmem();
          cout << "Memory cleared " << endl;
          break;
        case 'r': case 'R':
          recallmem();
          break;
        case 'i': case 'I':
          invert(num1);
          break;
        case char(10):  //10 represents the ASCII character for the 'Enter' key so that
                        //the following code will perform a calculation when 'Enter' is pressed
          if(build_num2 != ""){
            num2 = stod(build_num2);

            switch (op) {
              case '+':
                num1 = add(num1, num2);
                break;
              case '-':
                num1 = subtract(num1, num2);
                break;
              case '*':
                num1 = multiply(num1, num2);
                break;
              case '/':
                num1 = divide(num1, num2);
                break;
              case '^':
                num1 = power(num1, num2);
                break;
              default:
                break;

              }
            }
            cout << "> " << num1;
            first_entry = true;
            build_num1 = to_string(num1);
            build_num2 = "";

          default:
            break;
          }
    } while(key != 'x' && key != 'X');
}
