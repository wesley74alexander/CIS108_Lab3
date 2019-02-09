#include <iostream>
#include <string>
#include "Calculator.h"

using namespace std;

double num1;
double num2;
double stored;
bool first_entry = true;
char key;
char op;
char fun;
string build_num1 = "";
string build_num2 = "";

int main()
{
  cout << "\nThis is a calculator!\n" << "========================\n" << "> "; //Prompts user for input
	do {
		key = getchar(); // Gets user input one character at a time
		switch (key) {
			case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '0': case '.':
				if (first_entry == true){
				      build_num1 += key; //Concatinates each successive character to build a string of the first number
				}
				else {
				      build_num2 += key; //Concatinates characters to build a string of the second number but only once the first number has been built
				}
        break;
      case '+': case '-': case '*': case '/': case '^':
        if(build_num1 != ""){
          num1 = stod(build_num1); //Converts string of the first number to a double after an operator is entered
          build_num1 = "";
          build_num2 = "";
          first_entry = false;
          op = key;
          break;
        }
        else{
          cout << "You Must First Enter A Number!" << endl; //Error message in the event that user enters an operator before a entering a number
          break;
        }

        case 'c': case 'C': case 's': case 'S': case 'm': case 'M': case 'r': case 'R': case 'i': case 'I':
          fun = key;
          break;

        case char(10):  //10 represents the ASCII character for the 'Enter' key so that the following code will perform a calculation when 'Enter' is pressed
          if(build_num1 != ""){
            num1 = stod(build_num1); //Repeated code block from 33:36 so that the first number will convert to a double even if the user presses enter before entering an operator
            build_num1 = "";
            build_num2 = "";
            first_entry = false;
          }
          if(build_num2 != ""){
            num2 = stod(build_num2);
            build_num2 = "";
          }
        if (op != '\0') {
          switch (op) {
            case '+':
              num1 = cal::add(num1, num2);
              break;
            case '-':
              num1 = cal::subtract(num1, num2);
              break;
            case '*':
              num1 = cal::multiply(num1, num2);
              break;
            case '/':
              num1 = cal::divide(num1, num2);
              break;
            case '^':
              num1 = cal::power(num1, num2);
              break;
            default:
              break;
          }
          op = '\0'; //Resets operator before next loop commences so that the first operation called doesn't execute over and over.
        }
          switch (fun) {
          case 'c': case 'C':
            num1 = cal::clearval(num1, num2, build_num1, build_num2, first_entry); //This is where implementation of clearval() function falls short as referenced in line 51 of Calculator.cpp
            break;                                                                 //Function only returns one value (cal::num1), therefore only the global variable num1 is reset to 0. This is enough for the calculator to function just fine, but I'm still curious as to whether all five global variables can be reset with a single call of the function.
          case 's': case 'S':
            stored = cal::store(num1);
            cout << " Saved" << endl;
            break;
          case 'm': case 'M':
            stored = cal::clearmem(stored);
            cout << "Memory Cleared " << endl;
            break;
          case 'r': case 'R':
            num1 = cal::recallmem(stored);
            break;
          case 'i': case 'I':
            num1 = cal::invert(num1);
            break;
          default:
            break;
          }
          fun = '\0'; //Resets function before next loop commences so that the first function called doesn't execute over and over.
          if(num1 != 0){
            cout << "> " << num1; //Outputs answer to the console
            build_num1 = to_string(num1);
            build_num2 = "";
          }
          else{
            cout << "> "; //Outputs a blank prompt if the answer is 0. This isn't super necessary but it makes calculations performed after the calculator is cleared appear cleaner.
          }
          first_entry = true;
        default:
          break;
          }
    } while(key != 'x' && key != 'X'); //Exits the program
    cout << "========================\n" << "Goodbye!\n";
}
