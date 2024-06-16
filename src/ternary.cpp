#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename F>
double ternary(double l, double r, const F &f)
{
    if(r - l < 1e-5)
        return l + (r - l) / 2;

    double m1 = l + (r - l) / 3;
    double m2 = r - (r - l) / 3;
    return (f(m1) < f(m2) ?
        ternary(l, m2, f) :
        ternary(m1, r, f));
}


int main() {

    double t; cin >> t;
    double s = ternary(-100000, 100000, [&](double x)
    {
        return abs(x - t);
    });

    cout << s << endl;

    return 0;
}






