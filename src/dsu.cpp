#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

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

int main()
{
    int n; cin >> n;
    parent = vector<int>(n, -1);

    return 0;
}

