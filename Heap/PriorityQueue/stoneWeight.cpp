#include <bits/stdc++.h>
using namespace std;

int lastStoneWeight(vector<int> &stones)
{
    priority_queue<int> queue;

    for (int i = 0; i < stones.size(); i++)
    {
        queue.push(stones[i]);
    }

    while (queue.size() > 1)
    {
        int x = queue.top(); // heaviest stone
        queue.pop();

        int y = queue.top(); // second heaviest
        if (x == y)
        {
            queue.pop(); // if x == y, both stones are destroyed
        }

        else
        {
            queue.pop();
            queue.push(x - y);
        }
    }

    if (queue.empty())
    { // if queue is ever empty, answer will always be 0
        return 0;
    }

    return queue.top();
}
