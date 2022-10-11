#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> result(nums.size(), 1);

    int prefix = 1;
    int postfix = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        result[i] = prefix;
        prefix *= nums[i];
    }

    for (int i = nums.size() - 1; i > 0; i--)
    {
        result[i] = postfix * nums[i];
        postfix *= nums[i];
    }

    return result;
}