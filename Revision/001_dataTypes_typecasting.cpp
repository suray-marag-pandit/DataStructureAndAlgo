#include <iostream>
#include <iomanip> // For std::hex and std::setw
using namespace std;

int main() {
    // ------------------------------
    // 1. DATA TYPES IN C++
    // ------------------------------
    // Data types define the type of data a variable can store.

    // Integer data type (stores whole numbers)
    int age = 20;

    // Floating point data type (stores decimal numbers)
    float height = 5.9f;

    // Double data type (higher precision decimal numbers)
    double pi = 3.14159265359;

    // Character data type (stores a single character)
    char grade = 'A';

    // Boolean data type (true or false)
    bool isGraduated = false;

    // String is technically a class in C++
    string name = "Suray";

    // ------------------------------
    // 2. TYPECASTING IN C++
    // ------------------------------
    // Typecasting is converting one data type into another.

    float number = 9.99f;  
    
    // Implicit typecasting (done automatically by compiler)
    int implicitCast = number; // float -> int (decimal part truncated)

    // Explicit typecasting (manual conversion)
    int explicitCast = (int)number; // C-style cast
    int modernCast = static_cast<int>(number); // C++ style cast (recommended)

    cout << "Original float value: " << number << endl;
    cout << "Implicitly cast to int: " << implicitCast << endl;
    cout << "Explicitly cast (C-style): " << explicitCast << endl;
    cout << "Explicitly cast (C++ style): " << modernCast << endl;

    // you can also use the unsigned numeric data types
    unsigned int positiveNumber = 3000000000; // Only stores non-negative values
    cout << "Unsigned int value: " << positiveNumber << endl;
    

    // ------------------------------
    // 3. MEMORY STORAGE OF VARIABLES
    // ------------------------------
    // Each variable is stored in memory at a unique address.
    // The size depends on the data type and system architecture.

    cout << "\n--- Memory Information ---" << endl;

    cout << "Variable: age (int)\n";
    cout << "  Value: " << age 
         << "\n  Address: " << &age 
         << "\n  Size: " << sizeof(age) << " bytes\n\n";

    cout << "Variable: height (float)\n";
    cout << "  Value: " << height 
         << "\n  Address: " << &height 
         << "\n  Size: " << sizeof(height) << " bytes\n\n";

    cout << "Variable: pi (double)\n";
    cout << "  Value: " << pi 
         << "\n  Address: " << &pi 
         << "\n  Size: " << sizeof(pi) << " bytes\n\n";

    cout << "Variable: grade (char)\n";
    cout << "  Value: " << grade 
         << "\n  Address: " << (void*)&grade // Cast to void* to display properly
         << "\n  Size: " << sizeof(grade) << " byte\n\n";

    cout << "Variable: isGraduated (bool)\n";
    cout << "  Value: " << isGraduated 
         << "\n  Address: " << &isGraduated 
         << "\n  Size: " << sizeof(isGraduated) << " byte\n\n";

    cout << "Variable: name (string)\n";
    cout << "  Value: " << name 
         << "\n  Address: " << &name 
         << "\n  Size: " << sizeof(name) << " bytes (pointer & metadata)\n\n";

    // ------------------------------
    // BONUS: Demonstrate binary representation
    // ------------------------------
    cout << "--- Binary / Hex Representation ---" << endl;
    int x = 255;
    cout << "Decimal: " << x 
         << "\nHex: " << hex << x 
         << "\nOctal: " << oct << x << endl;

    return 0;


    //how to get negative of a number using bitwise operator 
    //or how negative number is stored in memory
    int a = 5;
    int b = ~a + 1; // Two's complement to get negative = 1's complement + 1
    cout<< b  <<endl;
}
 