#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> result;

    dfs(nums, 0, result);

    for (int i = 0; i < result.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
        }
        cout << "]" << endl;
    }

    return result;
}

void dfs(vector<int> &nums, int idx, vector<vector<int>> result)
{
    if (idx == nums.size())
    {
        result.push_back(nums);
        return;
    }

    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[i], nums[idx]);
        dfs(nums, idx + 1, result);
        swap(nums[i], nums[idx]);
    }
}