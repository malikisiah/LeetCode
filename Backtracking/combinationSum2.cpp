#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<int> curr;
    vector<vector<int>> result;

    dfs(candidates, target, 0, 0, curr, result);

    return result;
}

void dfs(vector<int> &candidates, int target, int sum, int idx, vector<int> &curr, vector<vector<int>> &result)
{
    if (sum > target)
    {
        return;
    }

    if (sum == target)
    {
        result.push_back(curr);
        return;
    }

    for (int i = idx; i < candidates.size(); i++)
    {
        if (i > idx && candidates[i] == candidates[i - 1])
        {
            continue;
        }

        curr.push_back(candidates[i]);
        dfs(candidates, target, sum + candidates[i], i + 1, curr, result);
        curr.pop_back();
    }
}