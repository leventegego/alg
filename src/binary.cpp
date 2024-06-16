#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

ull blen(ull x)
{
    ull r = 0; while(x >> r) ++r;
    return r;
}


ull msb(ull x)
{
    if(x == 0) return 0;
    ull mask = 1; while((x >> 1) >= mask) mask <<= 1;
    return mask;
}

ull lsb(ull x)
{
    if(x == 0) return 0;
    ull mask = 1; while((x & mask) == 0) mask <<= 1;
    return mask;
}

int main()
{
    int n; cin >> n;
    cout << blen(n) << endl;

    return 0;
}
