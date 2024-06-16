#include<bits/stdc++.h>
using namespace std;
using ll = long long;


template<typename F>
ll binsearch(ll l, ll r, const F &f) // [l, r)
{
    if(r - l == 1)
        return l;

    ll m = l + (r - l - 1) / 2;
    return (f(m) ?
        binsearch(l, m + 1, f) :
        binsearch(m + 1, r, f));
}


int main()
{
    ll n; cin >> n;
    ll r = binsearch(0, 1000000, [&](ll x){
        return x >= n;
    });

    cout << r << endl;
}

