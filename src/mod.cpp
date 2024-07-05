#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;


int mod = 1000000007; // 998244353;


int product(int a, int b) { return ((ll)a * b) % mod; }
int sum(int a, int b) { return ((a + b) % mod + mod) % mod; }
int modexp(int x, ll y)
{
    if(y == 0) return 1;
    return product(
        (y & 1 ? x : 1),
        modexp(product(x, x), y >> 1));
}
int inverse(int x) { return modexp(x, mod - 2); }


// int modexp(int x, ll y)
// {
//     int r = 1;
//     while(y)
//     {
//         if(y & 1)
//             r = product(r, x);
//         y = y >> 1;
//         x = product(x, x);
//     }
//     return r;
// }




int main()
{
    int n; cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int x, y; cin >> x >> y;
        cout << modexp(x, y) << endl;
    }

    return 0;
}

