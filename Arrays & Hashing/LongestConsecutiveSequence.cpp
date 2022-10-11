#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> set;

    for (auto x : nums)
    {
        set.insert(x);
    }

    int length = 0;
    int ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {

        if (set.find(nums[i] - 1) == set.end())
        {
            length = 1;
            while (set.find(nums[i] + length) != set.end())
            {
                length++;
            }
            ans = max(ans, length);
        }
    }

    return max(length, ans);
}