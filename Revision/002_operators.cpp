#include <iostream>
using namespace std;

int main() {
    cout << "==========================" << endl;
    cout << " C++ Operators Demonstration " << endl;
    cout << "==========================\n" << endl;

    // Variables for demonstration
    int a = 10, b = 3;

    // --------------------------------------
    // 1. Arithmetic Operators
    // --------------------------------------
    cout << "1. Arithmetic Operators:" << endl;
    cout << "a = " << a << ", b = " << b << endl;
    cout << "a + b = " << a + b << endl;  // Addition
    cout << "a - b = " << a - b << endl;  // Subtraction
    cout << "a * b = " << a * b << endl;  // Multiplication
    cout << "a / b = " << a / b << endl;  // Division (integer division)
    cout << "a % b = " << a % b << endl;  // Modulus
    cout << endl;

    // --------------------------------------
    // 2. Relational Operators
    // --------------------------------------
    cout << "2. Relational Operators:" << endl;
    cout << "a == b: " << (a == b) << endl;  // Equal to
    cout << "a != b: " << (a != b) << endl;  // Not equal to
    cout << "a > b: "  << (a > b) << endl;   // Greater than
    cout << "a < b: "  << (a < b) << endl;   // Less than
    cout << "a >= b: " << (a >= b) << endl;  // Greater than or equal to
    cout << "a <= b: " << (a <= b) << endl;  // Less than or equal to
    cout << endl;

    // --------------------------------------
    // 3. Logical Operators
    // --------------------------------------
    bool x = true, y = false;
    cout << "3. Logical Operators:" << endl;
    cout << "x && y (AND): " << (x && y) << endl;
    cout << "x || y (OR): "  << (x || y) << endl;
    cout << "!x (NOT): "     << (!x) << endl;
    cout << endl;

    // --------------------------------------
    // 4. Assignment Operators
    // --------------------------------------
    cout << "4. Assignment Operators:" << endl;
    int c = 5;
    cout << "Initial c = " << c << endl;
    c += 3;  // c = c + 3
    cout << "c += 3 -> " << c << endl;
    c -= 2;  // c = c - 2
    cout << "c -= 2 -> " << c << endl;
    c *= 4;  // c = c * 4
    cout << "c *= 4 -> " << c << endl;
    c /= 3;  // c = c / 3
    cout << "c /= 3 -> " << c << endl;
    c %= 5;  // c = c % 5
    cout << "c %= 5 -> " << c << endl;
    cout << endl;

    // --------------------------------------
    // 5. Increment & Decrement
    // --------------------------------------
    cout << "5. Increment & Decrement Operators:" << endl;
    int d = 10;
    cout << "Initial d = " << d << endl;
    cout << "Post-increment d++ = " << d++ << " (After: " << d << ")" << endl;
    cout << "Pre-increment ++d = " << ++d << endl;
    cout << "Post-decrement d-- = " << d-- << " (After: " << d << ")" << endl;
    cout << "Pre-decrement --d = " << --d << endl;
    cout << endl;

    // --------------------------------------
    // 6. Bitwise Operators
    // --------------------------------------
    cout << "6. Bitwise Operators:" << endl;
    cout << "a = " << a << " (in binary: 1010)" << endl;
    cout << "b = " << b << " (in binary: 0011)" << endl;
    cout << "a & b = " << (a & b) << " (AND)" << endl;
    cout << "a | b = " << (a | b) << " (OR)" << endl;
    cout << "a ^ b = " << (a ^ b) << " (XOR)" << endl;
    cout << "~a = " << (~a) << " (NOT)" << endl;
    cout << "a << 1 = " << (a << 1) << " (Left shift by 1)" << endl;
    cout << "a >> 1 = " << (a >> 1) << " (Right shift by 1)" << endl;
    cout << endl;

    // --------------------------------------
    // 7. Conditional (Ternary) Operator
    // --------------------------------------
    cout << "7. Conditional (Ternary) Operator:" << endl;
    int maxVal = (a > b) ? a : b;
    cout << "Max of a and b: " << maxVal << endl;
    cout << endl;

    // --------------------------------------
    // 8. sizeof Operator
    // --------------------------------------
    cout << "8. sizeof Operator:" << endl;
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of float: " << sizeof(float) << " bytes" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;
    cout << "Size of char: " << sizeof(char) << " byte" << endl;
    cout << endl;

    // --------------------------------------
    // 9. Comma Operator
    // --------------------------------------
    cout << "9. Comma Operator:" << endl;
    int i = (a = 5, b = 10, c = 10, a + b + c); // Evaluates left to right, final result is last expression
    cout << "Result of (a = 5, b = 10, c= 10, a + b + c) = " << i << endl;

    cout << "\n--- End of Demonstration ---" << endl;
    return 0;
}
