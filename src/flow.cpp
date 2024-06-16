#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int a, b;
    int c, f;
};

struct node
{
    vector<int> in, out;
};

struct graph
{
    vector<node> v;
    vector<edge> e;
};

bool bfs(graph &g, int s, int t, vector<int> &path, vector<bool> &bkw)
{
    path.clear();
    bkw.clear();

    vector<int> entry(g.v.size(), -1);
    bool found = false;

    vector<pair<int, bool>> que;
    for(int e : g.v[s].out) que.push_back({ e, false });
    for(int e : g.v[s].in) que.push_back({ e, true });

    for(int i = 0; i < (int)que.size(); ++i)
    {
        int ei = que[i].first;
        edge &e = g.e[ei];
        bool backward = que[i].second;
        int v = (backward ? e.a : e.b);

        if(
            (backward && e.f == 0) ||
            (!backward && e.f == e.c) ||
            (entry[v] != -1)
        )
            continue;

        entry[v] = ei;

        if(v == t)
        {
            found = true;
            break;
        }

        for(int e : g.v[v].out) que.push_back({ e, false });
        for(int e : g.v[v].in) que.push_back({ e, true });
    }

    if(found)
    {
        int v = t;
        while(v != s)
        {
            int ei = entry[v];
            edge &e = g.e[ei];
            path.push_back(ei);
            bkw.push_back(e.b != v);
            v = (e.b == v ? e.a : e.b);
        }
        reverse(path.begin(), path.end());
        reverse(bkw.begin(), bkw.end());
    }
    return found;
}

int ffa(graph &g, int s, int t)
{
    for(edge &e : g.e)
        e.f = 0;
    int f = 0;

    vector<int> path;
    vector<bool> bkw;
    while(bfs(g, s, t, path, bkw))
    {
        int d = INT_MAX;
        for(int i = 0; i < (int)path.size(); ++i)
        {
            edge &e = g.e[path[i]];
            d = min(d, (bkw[i] ? e.f : e.c - e.f));
        }
        for(int i = 0; i < (int)path.size(); ++i)
        {
            edge &e = g.e[path[i]];
            e.f += (bkw[i] ? -d : d);
        }
        f += d;
    }

    return f;
}

int main()
{
    int n, m;
    cin >> n >> m;

    graph g;
    g.v = vector<node>(n);
    g.e = vector<edge>(m);
    for(int ei = 0; ei < m; ++ei)
    {
        edge &e = g.e[ei];
        cin >> e.a >> e.b >> e.c;
        e.f = 0;
        g.v[e.a].out.push_back(ei);
        g.v[e.b].in.push_back(ei);
    }

    int f = ffa(g, 0, n - 1);
    cout << f << endl;

    return 0;
}

