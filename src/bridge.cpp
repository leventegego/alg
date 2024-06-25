#include<bits/stdc++.h>
using namespace std;
#define ff(i, n) for(int i = 0; i < (int)(n); ++i)



struct edge { int t, bridge; };
struct node
{
    vector<edge> nb;

    int vis;
    int cir;
};

int dfs_bridge(vector<node> &g, int p, int i)
{
    node &v = g[i];
    if(v.vis) { ++v.cir; return 1; } v.vis = 1;

    int cir = 0;

    for(edge &e : v.nb)
    {
        if(e.t == p) continue;
        int r = dfs_bridge(g, i, e.t);
        e.bridge = (r == 0);
        cir += r;
    }

    return cir - v.cir * 2;
}
int main()
{

    int n, m; cin >> n >> m;
    vector<node> g(n, (node){ vector<edge>(), 0, 0 });
    ff(i, m)
    {
        int u, v; cin >> u >> v; --u; --v;
        g[u].nb.push_back({ v, 0 });
        g[v].nb.push_back({ u, 0 });
    }

    ff(i, n)
    {
        if(!g[i].vis)
            dfs_bridge(g, -1, i);
    }

    return 0;
}





