#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;

vector<vi> ps(vector<vi> &a)
{
    int n = a.size();
    int m = a[0].size();
    vector<vi> ps(n + 1, vi(m + 1, 0));
    for(int i = 1; i < n + 1; ++i)
    for(int j = 1; j < m + 1; ++j)
        ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + a[i - 1][j - 1];

    return ps;
}

int main()
{


    return 0;
}

