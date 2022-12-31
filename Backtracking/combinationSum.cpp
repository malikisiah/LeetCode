#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> result;
    vector<int> curr;

    return result;
}

void dfs(vector<int> &candidates, int &target, int sum, int idx, vector<int> &curr, vector<vector<int>> &result)
{
    if (sum > target)
    {
        return;
    }

    if (sum == target)
    {
        result.push_back(curr);
    }

    for (int i = idx; i < candidates.size(); i++)
    {
        curr.push_back(candidates[i]);
        dfs(candidates, target, sum + candidates[i], i, curr, result);
        curr.pop_back();
    }
}
