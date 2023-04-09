#include <bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    unordered_map<int, vector<int>> graph;

    for (auto x : prerequisites)
    {
        graph[x[0]].push_back(x[1]);
    }

    unordered_set<int> visited;

    for (int i = 0; i < numCourses; i++)
    {
        if (!dfs(i, graph, visited))
        {
            return false;
        }
    }

    return true;
}

bool dfs(int course, unordered_map<int, vector<int>> &graph, unordered_set<int> &visited)
{
    if (visited.find(course) != visited.end())
    {
        return false;
    }

    if (graph[course].empty())
    {
        return true;
    }

    visited.insert(course);

    for (int i = 0; i < graph[course].size(); i++)
    {
        int j = graph[course][i];
        if (!dfs(j, graph, visited))
        {
            return false;
        }
    }

    graph[course].clear();
    visited.erase(course);

    return true;
}
