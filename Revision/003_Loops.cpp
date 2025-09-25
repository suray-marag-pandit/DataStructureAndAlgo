#include <iostream>
#include <vector>
using namespace std;

int main() {
    cout << "==============================\n";
    cout << " For Loops with Conditional Statements\n";
    cout << "==============================\n\n";

    // --------------------------------------------------
    // 1. Basic for loop with if-else (Even or Odd check)
    // --------------------------------------------------
    cout << "1. Basic for loop with if-else (Check even/odd):\n";
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            cout << i << " is even\n";
        } else {
            cout << i << " is odd\n";
        }
    }
    cout << "\n";

    // --------------------------------------------------
    // 2. For loop with else-if (Grade evaluation)
    // --------------------------------------------------
    cout << "2. For loop with else-if (Grade evaluation):\n";
    for (int marks = 50; marks <= 100; marks += 10) {
        if (marks >= 90) {
            cout << "Marks: " << marks << " -> Grade A\n";
        } else if (marks >= 70) {
            cout << "Marks: " << marks << " -> Grade B\n";
        } else if (marks >= 50) {
            cout << "Marks: " << marks << " -> Grade C\n";
        } else {
            cout << "Marks: " << marks << " -> Grade F\n";
        }
    }
    cout << "\n";

    // --------------------------------------------------
    // 3. Reverse for loop with condition
    // --------------------------------------------------
    cout << "3. Reverse for loop (Countdown from 5 to 1):\n";
    for (int i = 5; i >= 1; i--) {
        if (i == 3) {
            cout << "Three!\n";
        } else {
            cout << i << "\n";
        }
    }
    cout << "\n";

    // --------------------------------------------------
    // 4. Nested for loop + condition
    // --------------------------------------------------
    cout << "4. Nested for loop (Multiplication table, highlight multiples of 5):\n";
    for (int row = 1; row <= 5; row++) {
        for (int col = 1; col <= 5; col++) {
            int product = row * col;
            if (product % 5 == 0) {
                cout << "[" << product << "]\t"; // Highlight multiples of 5
            } else {
                cout << product << "\t";
            }
        }
        cout << endl;
    }
    cout << "\n";

    // --------------------------------------------------
    // 5. Range-based for loop + if-else
    // --------------------------------------------------
    cout << "5. Range-based for loop with condition (Check positive, negative, zero):\n";
    vector<int> numbers = {10, -5, 20, -3, 0};
    for (int num : numbers) {
        if (num > 0) {
            cout << num << " is positive\n";
        } else if (num < 0) {
            cout << num << " is negative\n";
        } else {
            cout << num << " is zero\n";
        }
    }
    cout << "\n";

    // --------------------------------------------------
    // 6. For loop with break and continue
    // --------------------------------------------------
    cout << "6. For loop with break and continue:\n";
    for (int i = 1; i <= 10; i++) {
        if (i == 3) {
            cout << "Skipping 3 (continue)\n";
            continue; // Skip iteration when i == 3
        }
        if (i == 7) {
            cout << "Stopping at 7 (break)\n";
            break; // Exit loop when i == 7
        }
        cout << "i = " << i << "\n";
    }
    cout << "\n";

    // --------------------------------------------------
    // 7. For loop + switch statement
    // --------------------------------------------------
    cout << "7. For loop with switch statement (Day of the week):\n";
    for (int day = 1; day <= 7; day++) {
        switch (day) {
            case 1: cout << "Day " << day << ": Monday\n"; break;
            case 2: cout << "Day " << day << ": Tuesday\n"; break;
            case 3: cout << "Day " << day << ": Wednesday\n"; break;
            case 4: cout << "Day " << day << ": Thursday\n"; break;
            case 5: cout << "Day " << day << ": Friday\n"; break;
            case 6: cout << "Day " << day << ": Saturday\n"; break;
            case 7: cout << "Day " << day << ": Sunday\n"; break;
            default: cout << "Invalid day\n";
        }
    }
    cout << "\n";

    // --------------------------------------------------
    // 8. Infinite for loop (stops manually using break)
    // --------------------------------------------------
    cout << "8. Infinite for loop demonstration (stops at 5):\n";
    int count = 1;
    for (;;) { // infinite loop
        cout << count << " ";
        count++;
        if (count > 5) {
            cout << "\nLoop stopped manually using break\n";
            break;
        }
    }

    
 char ch;

    // Taking character input
    cout << "Enter a single character: ";
    cin >> ch;

    // Conditional statements to check character type
    if (ch >= 'A' && ch <= 'Z') {
        cout << ch << " is an UPPERCASE letter." << endl;
    } 
    else if (ch >= 'a' && ch <= 'z') {
        cout << ch << " is a lowercase letter." << endl;
    } 
    else {
        cout << ch << " is NOT an alphabet letter." << endl;
    }

    cout << "\n--- End of Program ---" << endl;
    return 0;
}
