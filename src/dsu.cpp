#include <iostream>
#include <vector>

using namespace std;

struct dsu
{
    vector<int> parent;

    void build(int n)
    {
        parent = vector<int>(n, -1);
    }

    int findset(int v)
    {
        if(parent[v] == -1)
            return v;
        return parent[v] = findset(parent[v]);
    }

    void unionsets(int a, int b)
    {
        a = findset(a);
        b = findset(b);
        if(a == b)
            return;

        parent[b] = a;
    }
};

int main()
{
    int n; cin >> n;
    dsu d; d.build(n);

    return 0;
}

