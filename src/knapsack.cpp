#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll knapsack(vector<int> &v, vector<int> &w, int limit)
{
    // dp[i][j] : maximum sum(value) of any subset
    // of the first j items where sum(weight) <= i
    vector<vector<ll>> dp(limit + 1,
        vector<ll>(w.size() + 1, 0));

    for(int i = 0; i <= limit; ++i)
        for(int j = 1; j <= w.size(); ++j)
            dp[i][j] = i >= w[j - 1] ?
                max(dp[i][j - 1], dp[i - w[j - 1]][j - 1] + v[j - 1]) :
                dp[i][j - 1];

    return dp[limit][w.size()];
}



ll knapsack_opt(vector<int> &v, vector<int> &w, int limit)
{
    // dp[i][j] : maximal sum(v) of any subset
    // of the first j items where sum(w) <= i
    vector<ll> dp0(limit + 1, 0); // col j = 0
    vector<ll> dp1(limit + 1, 0); // col j = 1
    vector<ll> *prev = &dp0;
    vector<ll> *curr = &dp1;

    int top = limit - accumulate(w.begin(), w.end(), 0);
    int bot = *max_element(w.begin(), w.end());

    for(int j = 1; j <= w.size(); ++j)
    {
        int value = v[j - 1];
        int weight = w[j - 1];

        top += weight;
        bot += weight;

        for(int i = max(top, 0); i <= min(bot, limit); ++i)
        {
            (*curr)[i] = (i - weight >= 0) ?
                max((*prev)[i], (*prev)[i - weight] + value) :
                (*prev)[i];
        }

        swap(prev, curr);
    }

    return (*prev)[limit];
}


int main()
{

    return 0;
}