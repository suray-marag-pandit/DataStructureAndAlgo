// switch_and_functions_learning.cpp
// Learning example: switch, nested switch, and different types of functions
// Author: Suray Marag Pandit
// Date: 2025-09-24

#include <iostream>
using namespace std;

// ---------- Function Types ----------

// 1. Function with no parameters and no return value
void greet() {
    cout << "Welcome to the Function & Switch Learning Program!" << endl;
}

// 2. Function with parameters and no return value
void printSum(int a, int b) {
    cout << "Sum = " << (a + b) << endl;
}

// 3. Function with parameters and return value
int multiply(int a, int b) {
    return a * b;
}

// 4. Function with no parameters but returns a value
int getFavoriteNumber() {
    return 7;
}

// 5. Nested switch demonstration function
void nestedSwitchDemo() {
    int category, subCategory;

    cout << "Choose a category:\n1. Fruit\n2. Animal\n";
    cin >> category;

    switch(category) {
        case 1:
            cout << "Choose a fruit:\n1. Apple\n2. Banana\n";
            cin >> subCategory;
            switch(subCategory) {
                case 1: cout << "You selected Apple!\n"; break;
                case 2: cout << "You selected Banana!\n"; break;
                default: cout << "Unknown fruit.\n"; 
            }
            break;

        case 2:
            cout << "Choose an animal:\n1. Dog\n2. Cat\n";
            cin >> subCategory;
            switch(subCategory) {
                case 1: cout << "You selected Dog!\n"; break;
                case 2: cout << "You selected Cat!\n"; break;
                default: cout << "Unknown animal.\n";
            }
            break;

        default:
            cout << "Unknown category.\n";
    }
}

int main() {
    greet(); // call function with no parameters & no return

    int a, b;
    cout << "\nEnter two numbers: ";
    cin >> a >> b;

    printSum(a, b); // call function with parameters, no return
    cout << "Product = " << multiply(a, b) << endl; // call function with parameters and return

    int favNum = getFavoriteNumber(); // call function with no parameters but return
    cout << "My favorite number is: " << favNum << endl;

    cout << "\nNow let's try a nested switch example!\n";
    nestedSwitchDemo();

    return 0;
}
