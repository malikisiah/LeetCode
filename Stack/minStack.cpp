#include <bits/stdc++.h>
using namespace std;

class minStack
{
private:
    stack<pair<int, int>> minStck;
    int minElement;

public:
    minStack()
    {
    }

    void push(int val)
    {
        if (minStck.empty())
        {
            minStck.push({val, val});
        }

        else
        {
            if (val < minStck.top().second)
            {
                minStck.push({val, val});
            }
            else
            {
                minElement = minStck.top().second;
                minStck.push({val, minElement});
            }
        }
    }

    void pop()
    {
        minStck.pop();
    }

    int top()
    {
        return minStck.top().first;
    }

    int getMin()
    {
        return minStck.top().second;
    }
};