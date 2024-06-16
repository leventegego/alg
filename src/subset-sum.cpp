#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int subset_sum(vector<int> &s, int target)
{
    set<int> sums = { 0 };

    for(int x : s)
    {
        vector<int> newsums;
        for(int y : sums)
            if(x + y <= target)
                newsums.push_back(x + y);

        sums.insert(newsums.begin(), newsums.end());
    }

    return *sums.rbegin();
}

int subset_sum_opt(vector<int> &s, int target)
{
    map<int, int> c;
    for(int &x : s)
        ++c[x];

    vector<int> s_;

    for(auto &i : c)
    {
        if(i.second >= 3)
        {
            c[2 * i.first] += (i.second - 1) / 2;
            i.second = (i.second % 2 ? 1 : 2);
        }

        while(i.second--)
            s_.push_back(i.first);
    }

    return subset_sum(s_, target);
}

int main()
{
    

    return 0;
}

