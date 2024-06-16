#include <bits/stdc++.h>
using namespace std;

int kmp(string &s, string &p, vector<int> &pi)
{
    int n = s.size();
    int m = p.size();
    int c = 0;

    int i = 0;
    int j = 0;
    while(i < n)
    {
        if(s[i] == p[j])
        {
            ++i;
            ++j;
            if(j == m)
            {
                ++c;
                j = pi[j - 1];
            }
        }
        else
        {
            if(j) j = pi[j - 1];
            else ++i;
        }
    }

    return c;
}

vector<int> getpi(string &s)
{
    int n = s.size();
    vector<int> p(n, 0);

    for(int i = 1; i < n; ++i)
    {
        p[i] = p[i - 1];
        while(p[i] > 0 && s[p[i]] != s[i])
            p[i] = p[p[i] - 1];

        p[i] += (s[p[i]] == s[i]);
    }

    return p;
}


