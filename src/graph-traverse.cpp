#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int n;
vector<vector<int>> graph;
vector<vector<int>> weight;

void bfs(int i)
{
    vector<bool> found(n, false);
    list<int> que = { i };

    while(!que.empty())
    {
        int v = que.front();
        que.pop_front();

        if(found[v])
            continue;
        found[v] = true;

        que.insert(que.end(), graph[v].begin(), graph[v].end());
    }
}

void dfs(int i)
{
    vector<bool> found(n, false);
    list<int> que = { i };

    while(!que.empty())
    {
        int v = que.back();
        que.pop_back();

        if(found[v])
            continue;
        found[v] = true;

        que.insert(que.end(), graph[v].begin(), graph[v].end());
    }
}

struct dcomp
{
    bool operator()(pii a, pii b)
    {
        return a.second > b.second;
    }
};

void dijkstra(int i)
{
    vector<bool> found(n, false);
    vector<int>dist(n, -1);

    priority_queue<pii> que;
    que.push({ 0, i });
    while(!que.empty())
    {
        int d, v;
        tie(d, v) = que.top();
        que.pop();
        d = -d;

        if(found[v])
            continue;
        found[v] = true;

        dist[v] = d;
        for(int j = 0; j < graph[v].size(); ++j)
            que.push({ -(d + weight[v][j]), graph[v][j] }); // use opposite of distance as priority
    }

}


int main()
{
    int m;
    cin >> n >> m;
    graph = vector<vector<int>>(n);
    weight = vector<vector<int>>(n);

    for(int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
        weight[u - 1].push_back(w);
        weight[v - 1].push_back(w);
    }

    dijkstra(0);


    return 0;
}

