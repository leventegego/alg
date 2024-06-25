#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

// int gcd(int a, int b)
// {
//     tie(a, b) = minmax({ a, b });
//     int r = a;
//     while(b % a)
//     {
//         r = b % a;
//         b = a;
//         a = r;
//     }

//     return r;
// }

int gcd(int a, int b)
{
    if(a > b) swap(a, b);
    if(a == 0) return b;
    return gcd(a, b - a);
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    int n; cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int a, b; cin >> a >> b;
        cout <<
            a << " " << b << " -> " <<
            gcd(a, b) << " " << lcm(a, b) <<
            endl;
    }
    return 0;
}
