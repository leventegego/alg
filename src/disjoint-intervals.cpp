#include <bits/stdc++.h>
using namespace std;

struct interval { int l, r; };

bool operator<(const interval &a, const interval &b)
{
    return a.r < b.r;
}

interval join_interval(interval &a, interval &b)
{
    return { min(a.l, b.l), max(a.r, b.r) };
}

vector<interval> disjoint(vector<interval> &a)
{
    int n = a.size();
    sort(a.begin(), a.end());

    vector<interval> st;

    for(interval i : a)
    {
        while(!st.empty() && i.l <= st.back().r)
        {
            i = join_interval(i, st.back());
            st.erase(st.end() - 1);
        }
        st.push_back(i);
    }

    return st;
}


int main()
{
    int n; cin >> n;
    vector<interval> a(n);
    for(interval &x : a)
        cin >> x.l >> x.r;


    vector<interval> d = disjoint(a);


    return 0;
}