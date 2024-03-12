#include <iostream>
using namespace std;

int fb(long long a, long long b, long long c, long long n, long long m)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }

    int ans = a * fb(a, b, c, n - 1, m) + b * fb(a, b, c, n - 2, m) + c;

    return ans%m;
}

int main(int argc, char const *argv[])
{
    int a = 3, b = 3, c = 3, n = 3, m = 5;

    cout<<fb(a,b,c,n,m)<<endl;
    return 0;
}
