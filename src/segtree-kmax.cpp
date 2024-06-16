#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node;

int n, k;
vector<int> a;
vector<node> t;


template<typename T>
void printVec(vector<T> &v)
{
    for(int i=0; i<v.size(); ++i) {
        cout << (i ? ", " : "") << v[i];
    }
    cout << endl;
}

struct node {
	int count;
	vector<ll> kBiggest;
	vector<ll> prefixSum;

    node() {}
    
    // Levél konstruktor.
	node(int tl, int tr) : count(tr - tl + 1) {
		kBiggest = vector<ll>(a.begin() + tl, a.begin() + tr + 1);
        sort(kBiggest.begin(), kBiggest.end());
		prefixSum = vector<ll>(count + 1, 0);
		for(int j = 0; j < count; ++j)
		{
			prefixSum[j + 1] = prefixSum[j] + kBiggest[j];
		}
	}

    void print()
    {
        cout << "Elemek: ";
        printVec(kBiggest);

        cout << "Prefixösszeg: ";
        printVec(prefixSum);
    }
};

node add(node &a, node &b) {
	node r;
    r.count = k;
    r.kBiggest = vector<ll>(k);
    r.prefixSum = vector<ll>(k+1, 0);
    
    int i=a.count-1;
    int j=b.count-1;

    for(int m = k-1; 0<=m; m--) {
        if(0<=i && (j<0 || a.kBiggest[i] > b.kBiggest[j])) {
            r.kBiggest[m] = a.kBiggest[i];
            i--;
        } else {
            r.kBiggest[m] = b.kBiggest[j];
            j--;
        }
    }

    for(int j = 0; j < k; ++j)
    {
        r.prefixSum[j + 1] = r.prefixSum[j] + r.kBiggest[j];
    }
	
	return r;
}

void build(int v, int tl, int tr) {

    if (tl == tr) {
        t[v] = node(tl, tr);
        return;
    }
    
    int tm = (tl + tr) / 2;
    build(v*2, tl, tm);
    build(v*2+1, tm+1, tr);
    
    if (tr - tl + 1 <= k) {
		t[v] = node(tl, tr);
    } else {
        t[v] = add(t[v*2], t[v*2+1]);
    }
}

void queryParts(int v, int tl, int tr, int l, int r, vector<int>& indexes) {

    if (l > r) return;

    if (l == tl && r == tr) {
        indexes.push_back(v);
        return;
    }

    int tm = (tl + tr) / 2;
    queryParts(v*2, tl, tm, l, min(r, tm), indexes);
    queryParts(v*2+1, tm+1, tr, max(l, tm+1), r, indexes);
}


// ll sum(int l, int r) {

//     t.resize(4 * n);

//     vector<int> indexes;
//     queryParts(1, 0, n - 1, l, r, indexes);

    
//     return 0;
// }


void print(int v, int tl, int tr) {
    cout << "Csúcs: " << v << " [" << tl << "," << tr << "]" << endl;
    
    if (tr == tl) {
		cout << "Levél: " << t[v].count << " db" << endl;
        t[v].print();

        cout << endl;
     } else {
        cout << "Belső: " << t[v].count << " db" << endl;
        t[v].print();
        int tm = (tl + tr) / 2;
        cout << "Gyerekek: " << endl;
        cout << "- Csúcs: " << v*2 << " [" << tl << "," << tm << "]" << endl;
        cout << "- Csúcs: " << v*2+1 << " [" <<  tm+1 << "," << tr << "]" << endl;

        cout << endl;
        
        print(v*2, tl, tm);
        print(v*2+1, tm+1, tr);
    }

    
}

int main()
{
	cin >> n >> k;
	a.resize(n);
    t.resize(4*n);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num; 
		a[i] = num;
	}
    build(1, 0, n - 1);
    
    vector<int> result;
    queryParts(1, 0, n-1, 1, n-2, result);
    cout << "Result: ";
    printVec(result);
    cout << endl;

    for(int i=0; i<result.size(); ++i) {
        t[result[i]].print();
    }

    cout<<endl;
    
   // print(1, 0, n - 1);


	
	return 0;
}