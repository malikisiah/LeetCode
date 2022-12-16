#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    vector<vector<int>> result;
    priority_queue<pair<double, vector<int>>> prioQueue;

    for (int i = 0; i < points.size(); i++)
    {
        prioQueue.push(make_pair(distanceToOrigin(points[i]), points[i]));
    }

    while (prioQueue.size() > k)
    {
        prioQueue.pop();
    }

    while (!prioQueue.empty())
    {
        result.push_back(prioQueue.top().second);
        prioQueue.pop();
    }

    return result;
}

double distanceToOrigin(vector<int> orderedPair)
{
    double x = pow(orderedPair[0], 2);
    double y = pow(orderedPair[1], 2);

    return sqrt(x + y);
}