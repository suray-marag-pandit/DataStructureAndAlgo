
// #include<iostream>
// #include<bitset>
// using namespace std;

// int main(){
//     int n;
//     cin>>n;
//     cout<<bitset<32>(n);
//     return 0;
// }

// Online C++ compiler to run C++ program online
#include <iostream>
#include<math.h>
using namespace std;

int main() {
    // Write C++ code here
    int number = 5;
    
    int binary= 0;
    int i = 0;
    while(number>0){
        int bit = number & 1;
        binary = bit * pow(10,i++) + binary;
        number =number>>1;
    }
    cout<<endl<<binary;

    return 0;
}

// Your code is converting a decimal number (`number`) to its **binary representation**, but there's a small issue with the logic. Let's break it down step-by-step and then improve it.

// ---

// ### **Step-by-step Explanation**

// The goal: Convert `number = 5` (decimal) → `101` (binary).

// #### **Code Walkthrough**

// ```cpp
// int number = 5;       // initial number
// int binary = 0;       // to store binary representation
// int i = 0;            // to track position (power of 10)
// ```

// ---

// ### **Inside the while loop**

// The loop runs while `number > 0`.

// 1. **First iteration:**

//    * `number = 5` → binary is `101` in base 2
//    * `bit = number & 1 = 5 & 1 = 1`
//    * `binary = bit * pow(10, i++) + binary`

//      * Here `pow(10, 0) = 1`
//      * `binary = 1 * 1 + 0 = 1`
//    * `number = number >> 1` → `5 >> 1 = 2`
//    * `i = 1`

// ---

// 2. **Second iteration:**

//    * `number = 2`
//    * `bit = 2 & 1 = 0`
//    * `pow(10, 1) = 10`
//    * `binary = 0 * 10 + 1 = 1`
//    * `number = 2 >> 1 = 1`
//    * `i = 2`

// ---

// 3. **Third iteration:**

//    * `number = 1`
//    * `bit = 1 & 1 = 1`
//    * `pow(10, 2) = 100`
//    * `binary = 1 * 100 + 1 = 101`
//    * `number = 1 >> 1 = 0`
//    * `i = 3`

// ---

// Loop stops as `number = 0`.
// **Final result:** `binary = 101`

// ---

// ### **Problem in Current Code**

// Your code works correctly for small numbers but has **two issues**:

// 1. **Using `pow(10, i)` is risky**

//    * `pow()` returns a `double`, which can introduce floating-point inaccuracies for larger values of `i`.

// 2. **Storing binary as an integer**

//    * If the binary form is very large (like 32 bits), it may **overflow** an integer.

// ---

// ### **Better and Safer Version**

// Instead of building the binary using `pow(10, i)`, just **append digits as characters** or build a string.

// ---

// #### **Improved Code: Using a String**

// ```cpp
// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     int number = 5;
//     string binary = "";

//     while (number > 0) {
//         int bit = number & 1;          // get last bit
//         binary = to_string(bit) + binary; // prepend bit to the string
//         number = number >> 1;          // right shift
//     }

//     cout << "Binary: " << binary << endl;
//     return 0;
// }
// ```

// ---

// ### **Output**

// ```
// Binary: 101
// ```

// ---

// ### **Why This is Better**

// * No floating-point operations → **accurate and safe**.
// * Works for very large numbers without overflow.
// * Cleaner and easier to understand.

// ---

// ### **If You Really Want to Keep Integer Method**

// Avoid `pow()` and just use multiplication by 10:

// ```cpp
// #include <iostream>
// using namespace std;

// int main() {
//     int number = 5;
//     int binary = 0;
//     int place = 1;

//     while (number > 0) {
//         int bit = number & 1;
//         binary = bit * place + binary;  // directly use place
//         place *= 10;                     // move to next position
//         number = number >> 1;
//     }

//     cout << "Binary: " << binary << endl;
//     return 0;
// }
// ```

// ---

// ### **Summary**

// | Approach                    | Safe for Large Numbers | Performance | Simplicity |
// | --------------------------- | ---------------------- | ----------- | ---------- |
// | Using `pow(10, i)`          | ❌ Floating-point risk  | ⚠️ Slower   | Moderate   |
// | Using integer `place *= 10` | ✅ Safe                 | ✅ Faster    | ✅ Simple   |
// | Using string                | ✅ Very safe            | ✅ Efficient | ✅ Clean    |

// **Best practice:** Use a **string approach** for correctness and simplicity.
