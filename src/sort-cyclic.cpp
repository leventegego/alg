#include <bits/stdc++.h>
using namespace std;

vector<int> sort_cyclic(string s)
{
    int n = s.size();

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int a, int b)
        { return s[a] < s[b]; });       // O(nlogn)

    vector<int> c(n, 0);
    for(int i = 1; i < n; ++i)
        c[p[i]] = c[p[i - 1]] + (s[p[i]] != s[p[i - 1]]);


    // itt kesz a p es c az 1 hosszu substringekre


    for(int h = 1; h < n; h *= 2)
    {
        // 2h hosszu stringekre p es c szamolasa

        // cnt[i] = h hosszu substringek szama az i. ekvivalencia osztalyban -> prefix sum
        vector<int> cnt(256, 0);
        for(int x : c)
            ++cnt[x];
        for(int i = 1; i < 256; ++i)
            cnt[i] += cnt[i - 1];

        // p[i] = Hol kezdodik az a 2h hosszu substring, ami az elso fele szerint az i.
        // pn[i] = Hol kezdodik az a 2h hosszu substring, ami a masodik fele szerint az i.
        vector<int> pn(n);
        for (int i = 0; i < n; i++)
            pn[i] = (p[i] - h + n) % n;

        // p ujrarendezese: eddigi p elsodleges, pn masodlagos
        for (int i = n - 1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];

        // c[i] < c[j]  <=>  i.helyen kezdodo substring < j.helyen kezdodo substring
        vector<int> cn(n, 0);
        for (int i = 1; i < n; i++)
        {
            int ic = p[i];
            int ip = p[i - 1];
            pair<int, int> curr = { c[ic], c[(ic + h) % n] };
            pair<int, int> prev = { c[ip], c[(ip + h) % n] };
            cn[ic] = cn[ip] + (curr != prev);
        }
        c.swap(cn);
    }

    return p;
}


int main()
{
    string s; cin >> s;
    s += '$'; // [input karakterek] > '$'

    vector<int> p = sort_cyclic(s);
    for(int i = 1; i < p.size(); ++i) // elso a $-el kezdodo
        cout << p[i] << endl;

    return 0;
}

