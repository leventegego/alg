#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    std::tie(a, b) = std::minmax({ a, b });
    int r = a;
    while(b % a)
    {
        r = b % a;
        b = a;
        a = r;
    }

    return r;
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int main()
{

    return 0;
}
