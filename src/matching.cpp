#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int a, b;
    int other(int i) { return (a == i ? b : a); }
};

struct node
{
    vector<int> e;
};

struct graph
{
    vector<node> v;
    vector<edge> e;

    void add_edge(int a, int b)
    {
        int ei = e.size();
        e.push_back({ a, b });
        v[a].e.push_back(ei);
        v[b].e.push_back(ei);
    }
};

bool dfs(graph &g, int i,
    vector<bool> &mv, vector<bool> &me,
    vector<bool> &found, vector<int> &path)
{
    bool c = (path.size() % 2);

    if(found[i] || (path.empty() && mv[i]))
        return false;
    if(path.size() && !mv[i])
        return c;

    found[i] = true;

    for(int ei : g.v[i].e) if(me[ei] == c)
    {
        path.push_back(ei);
        if(dfs(g, g.e[ei].other(i), mv, me, found, path))
            return true;
        path.pop_back();
    }

    return false;
}

void maxmatch(graph &g, vector<bool> &mv, vector<bool> &me)
{
    mv = vector<bool>(g.v.size(), false);
    me = vector<bool>(g.e.size(), false);

    for(int i = 0; i < (int)g.v.size(); ++i)
    {
        vector<bool> found(g.v.size(), false);
        vector<int> path;
        if(dfs(g, i, mv, me, found, path))
        {
            for(int ei : path)
                me[ei] = !me[ei];

            mv[i] = true;
            mv[g.e[path.back()].a] = true;
            mv[g.e[path.back()].b] = true;
        }
    }
}


int main()
{
    int n, m;
    cin >> n >> m;

    graph g;
    g.v = vector<node>(n);
    for(int ei = 0; ei < m; ++ei)
    {
        int a, b; cin >> a >> b;
        g.add_edge(a, b);
    }

    vector<bool> mv, me;
    maxmatch(g, mv, me);

    cout << count(me.begin(), me.end(), true) << endl;

    return 0;
}

