#include <iostream>
#include <vector>

using namespace std;

vector<int> t;

void build(vector<int> &a, int i, int lt, int rt)
{
    if(rt - lt == 1)
    {
        t[i] = a[lt];
        return;
    }

    t[i] = 0;

    int mid = (lt + rt) / 2;
    build(a, i * 2, lt, mid);
    build(a, i * 2 + 1, mid, rt);
}

void update(int i, int lt, int rt, int l, int r, int x)
{
    if(lt == l && rt == r)
    {
        t[i] += x;
        return;
    }


    int mid = (lt + rt) / 2;
    if(r <= mid)
        update(i * 2, lt, mid, l, r, x);
    else if(l >= mid)
        update(i * 2 + 1, mid, rt, l, r, x);
    else
    {
        update(i * 2, lt, mid, l, mid, x);
        update(i * 2 + 1, mid, rt, mid, r, x);
    }
}

int query(int i, int lt, int rt, int j)
{
    if(rt - lt == 1)
        return t[i];


    int mid = (lt + rt) / 2;
    if(j < mid)
        return t[i] + query(i * 2, lt, mid, j);
    else
        return t[i] + query(i * 2 + 1, mid, rt, j);
}

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int &x : a)
        cin >> x;

    t = vector<int>(4 * n + 1, 0);
    build(a, 1, 0, n);

    return 0;
}

