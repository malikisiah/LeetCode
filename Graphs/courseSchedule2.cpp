#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> result;
    unordered_map<int, vector<int>> adj;

    for (auto x : prerequisites)
    {
        adj[x[0]].push_back(x[1]);
    }

    unordered_set<int> cycle;
    unordered_set<int> visited;

    for (int i = 0; i < numCourses; i++)
    {
        if (!dfs(i, adj, visited, cycle, result))
        {
            return {};
        }
    }
    return result;
}

bool dfs(int course, unordered_map<int, vector<int>> &adj, unordered_set<int> &visited, unordered_set<int> &cycle, vector<int> &result)
{
    if (cycle.find(course) != cycle.end())
    {
        return false;
    }

    if (visited.find(course) != cycle.end())
    {
        return true;
    }

    cycle.insert(course);

    for (int i = 0; i < adj[course].size(); i++)
    {
        int nextCourse = adj[course][i];
        if (!dfs(nextCourse, adj, visited, cycle, result))
        {
            return false;
        }
    }

    cycle.erase(course);
    visited.insert(course);
    result.push_back(course);

    return true;
}
