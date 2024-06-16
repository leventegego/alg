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

void update(vector<int> &bit, int i, int x)
{
    i += 1;
    while(i < bit.size())
    {
        bit[i] += x;
        i += i & (-i);
    }
}

int query(vector<int> &bit, int i) // S[0, i]
{
    i += 1;
    int sum = 0;
    while(i > 0)
    {
        sum += bit[i];
        i -= i & (-i);
    }
    return sum;
}

int main()
{

    int n; cin >> n;
    vector<int> a(n);
    for(int &x : a)
        cin >> x;

    vector<int> tree(n + 1, 0);
    for(int i = 0; i < n; ++i)
        update(tree, i, a[i]);


    return 0;
}

