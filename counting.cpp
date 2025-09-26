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

    cout << a + b << " ";
    fibonacci(b, a + b, n - 1);
}
int main()
{
    // counting(10);

    // counting2(10);

    fibonacci(0, 1, 8);
    return 0;
}