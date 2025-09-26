#include <iostream>
using namespace std;

void counting(int n)
{
    if (n == 0)
        return;
    cout << n << endl;
    counting(n - 1);
}
void counting2(int n)
{
    if (n == 0)
        return;
    counting2(n - 1);
    cout << n << endl;
}

void fibonacci(int a, int b, int n)
{
    if (n == 0)
        return;

    fibonacci(b, a + b, n - 1);
    cout << a + b << " ";
}

int factorial(int n)
{
    if (n == 0)
        return 1;

    return n * factorial(n - 1);
}

int stairCaseProblem(int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    return stairCaseProblem(n - 1) + stairCaseProblem(n - 2);
}

void sayMyName(string arr[], int number)
{
    if (number == 0)
        return;

    int onesDigit = number % 10;
    sayMyName(arr, number / 10);
    cout << arr[onesDigit];
}

bool isSorted(int arr[], int size)
{
    if (size == 0 || size == 1)
        return true;
    if (arr[0] > arr[1])
        return false;

    return isSorted(arr + 1, size - 1);
}

int sum(int arr[], int size)
{
    if (size == 0)
        return 0;

    return arr[0] + sum(arr + 1, size - 1);
}

bool binarySearch(int arr[], int low, int high, int key) {
    if (low > high)
        return false; // Base case: key not found

    int mid = low + (high - low) / 2; // Prevent overflow

    if (arr[mid] == key)
        return true; // Key found
    else if (arr[mid] > key)
        return binarySearch(arr, low, mid - 1, key); // Search left half
    else
        return binarySearch(arr, mid + 1, high, key); // Search right half
}
void reverseString(char s[],int start,int end){
    if(start>end) return;
    swap(s[start],s[end]);
    reverseString(s,start+1,end-1);

}

int power(int n,int k){
    if(k==0) return 1;
    return n*power(n,k-1);
}
int main()
{
    // counting(10);

    // counting2(10);

    // fibonacci(0, 1, 8);

    // cout<< stairCaseProblem(3);
    // string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    // sayMyName(arr,423);
    // cout<<factorial(5);

    int test4[] = {1, 2, 3, 5, 6, 10};

    //    cout<<isSorted(test4,6);

    // cout<<sum(test4,6);

    // cout << binarySearch(test4,0,6,11);


    // char arr[6] = "abcde";
    // reverseString(arr,0,5);
    // for(auto i:arr){
    //     cout<<i;
    // }

    cout<<power(2,10);
    return 0;
}