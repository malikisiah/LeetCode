#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k);

int main()
{
    vector<int> nums = {4, 1, -1, 2, -1, 2, 3};

    topKFrequent(nums, 2);
}

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> map;
    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < nums.size(); i++)
    {
        map[nums[i]]++;
    }

    for (auto it = map.begin(); it != map.end(); it++)
    {
        pq.push({it->second * -1, it->first});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    vector<int> result;

    while (!pq.empty())
    {
        result.push_back(pq.top().second);
        pq.pop();
    }

    return result;
}