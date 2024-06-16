#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct vec { ll x, y; };
vec operator+(vec a, vec b) { return { a.x + b.x, a.y + b.y }; }
vec operator-(vec a, vec b) { return { a.x - b.x, a.y - b.y }; }
ll dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }
ll cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
vec operator*(vec a, ll b) { return { a.x * b, a.y * b }; }
istream &operator>>(istream &is, vec &x) { return is >> x.x >> x.y; }

vec point(vector<ll> &f, int i)
{
    return { i, f[i] };
}


// tuple<ll, ll, ll> split(ll a, ll b)
// {
//     ll mod = 100000000;

//     ll a1 = a / mod; ll a2 = a % mod;
//     ll b1 = b / mod; ll b2 = b % mod;

//     ll s1 = a2 * b2;
//     ll s2 = a1 * b2 + a2 * b1;
//     ll s3 = a1 * b1;

//     s2 += s1 / mod; s1 %= mod;
//     s3 += s2 / mod; s2 %= mod;

//     return { s3, s2, s1 };
// }

bool right(vec v0, vec v1, vec v2) // v0-v1-v2 triangle is right handed
{
    // return (cross(v1 - v0, v2 - v0) > 0); // overflows??

    vec d1 = v1 - v0;
    vec d2 = v2 - v0;

    // return split(d1.x, d2.y) > split(d2.x, d1.y);

    return (double)d1.x * d2.y > (double)d2.x * d1.y;
}


void conv_hull(vector<ll> &f, int l, int r, vector<int> &buf) // convex hull of f in range [l, r)
{
    buf.resize(r - l);

    buf[0] = l;
    int j = 1;

    for(int i = l + 1; i < r; ++i)
    {
        while(j >= 2 && !right(
            point(f, buf[j - 2]),
            point(f, buf[j - 1]),
            point(f, i)
        ))
            --j;

        buf[j] = i;
        ++j;
    }

    buf.resize(j);
}



