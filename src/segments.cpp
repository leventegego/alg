#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;


struct seg
{
    int l, r;
};

int diff(seg a, seg b) //  |a\b|
{
    return 
        max(b.l - a.l, 0) - max(b.l - a.r, 0) + 
        max(a.r - b.r, 0) - max(a.l - b.r, 0);
}


int main()
{

    return 0;
}

