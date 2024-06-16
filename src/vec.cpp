#include <bits/stdc++.h>
using namespace std;

// struct vec { double x, y; };
// vec operator+(vec a, vec b) { return { a.x + b.x, a.y + b.y }; }
// vec operator-(vec a, vec b) { return { a.x - b.x, a.y - b.y }; }
// vec operator*(vec a, double b) { return { a.x * b, a.y * b }; }
// double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }
// double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
// double len(vec a) { return sqrt(dot(a, a)); }
// vec norm(vec a) { return a * (1.0 / len(a)); }
// istream &operator>>(istream &is, vec &x) { return is >> x.x >> x.y; }



struct vec { int x, y; };
vec operator+(vec a, vec b) { return { a.x + b.x, a.y + b.y }; }
vec operator-(vec a, vec b) { return { a.x - b.x, a.y - b.y }; }
vec operator*(vec a, int b) { return { a.x * b, a.y * b }; }
int dot(vec a, vec b) { return a.x * b.x + a.y * b.y; }
int cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
bool operator==(const vec &v1, const vec &v2) { return (v1.x == v2.x && v1.y == v2.y); }
bool operator<(const vec &v1, const vec &v2) { return (v1.x < v2.x) || (v1.x == v2.x && v1.y < v2.y); }
istream &operator>>(istream &is, vec &x) { return is >> x.x >> x.y; }



int main()
{

    return 0;
}



