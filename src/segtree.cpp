#include <bits/stdc++.h>
using namespace std;

struct node
{
    int l, r;

    int x;
};

node create(vector<int> &a, int i) { return { i, i + 1, a[i] }; }
node combine(node a, node b) { return { a.l, b.r, a.x + b.x }; }
void update_node(node &n, int x) { n.x += x; }

struct segtree
{
    vector<node> t;

    segtree(vector<int> &a) : t(a.size() * 4 + 1) { build(a, 0, a.size(), 1); }
    void build(vector<int> &a, int l, int r, int i)
    {
        if(r - l == 1) { t[i] = create(a, l); return; }

        int mid = (l + r) / 2;
        build(a, l, mid, 2 * i);
        build(a, mid, r, 2 * i + 1);

        t[i] = combine(t[2 * i], t[2 * i + 1]);
    }

    node query(int l, int r, int i = 1) // [l, r)
    {
        if(t[i].l == l && t[i].r == r)
            return t[i];

        int mid = (t[i].l + t[i].r) / 2;

        if(r <= mid) return query(l, r, i * 2);
        if(l >= mid) return query(l, r, i * 2 + 1);

        return combine(
            query(l, mid, i * 2),
            query(mid, r, i * 2 + 1));
    }

    void update(int j, int x, int i = 1)
    {
        update_node(t[i], x);

        if(t[i].r - t[i].l == 1)
            return;

        int mid = (t[i].l + t[i].r) / 2;
        update(j, x, i * 2 + (j < mid));
    }
};

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;

    segtree t1(a);

    int q; cin >> q;
    for(int i = 0; i < q; ++i)
    {
        int l, r; cin >> l >> r;
        cout << t1.query(l, r).x << endl;
    }




    return 0;
}

