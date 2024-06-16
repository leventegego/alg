#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;


int mod = 1000000007;

int product(int a, int b) { return ((ll)a * b) % mod; }
int sum(int a, int b) { return ((a + b) % mod + mod) % mod; }
int modexp(int x, ll y)
{
    int r = 1;
    while(y)
    {
        if(y & 1)
            r = product(r, x);
        y = y >> 1;
        x = product(x, x);
    }
    return r;
}
int inverse(int x) { return modexp(x, mod - 2); }


int main()
{
    

    return 0;
}

