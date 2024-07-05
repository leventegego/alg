// Program showing a policy-based data structure.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <iostream>
using namespace __gnu_pbds;
using namespace std;

using vi = vector<int>;
using ordered_set = tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
	tree_order_statistics_node_update
>;

int main()
{
    int n; cin >> n;
    vi a(n); for(auto &x : a) cin >> x;

	ordered_set s;
    for(int &x : a) s.insert(x);


    for(const int &x : s) cout << x << endl;

    cout << "\n";

	cout << *s.find_by_order(3) << endl;
	cout << s.order_of_key(6) << endl;
    cout << s.order_of_key(7) << endl;


	return 0;
}


