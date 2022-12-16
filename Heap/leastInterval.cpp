#include <bits/stdc++.h>
using namespace std;

int leastInterval(vector<char> &tasks, int n)
{
    unordered_map<char, int> map;
    queue<pair<int, int>> q;
    priority_queue<int> prioQ;

    for (auto x : tasks)
    {
        map[x]++;
    }

    for (auto x : map)
    {
        prioQ.push(x.second);
    }
    int time = 0;
    do
    {
        if (!prioQ.empty())
        {
            int val = prioQ.top() - 1;
            prioQ.pop();
            time++;

            if (val != 0)
            {
                q.push(pair<int, int>(val, time + n));
            }
        }

        else
        {
            time++;
        }

        if (q.front().second == time)
        {
            prioQ.push(q.front().first);
            q.pop();
        }

    } while (!q.empty() || !prioQ.empty());

    return time;
}
