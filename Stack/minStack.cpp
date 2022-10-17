#include <bits/stdc++.h>
using namespace std;

class minStack
{
private:
    stack<pair<int, int>> stack;
    int minElement;

public:
    minStack()
    {
    }

    void push(int val)
    {
        if (stack.empty())
        {
            stack.push({val, val});
        }

        else
        {
            if (val < stack.top().second)
            {
                stack.push({val, val});
            }
            else
            {
                minElement = stack.top().second;
                stack.push({val, minElement});
            }
        }
    }

    void pop()
    {
        stack.pop();
    }

    int top()
    {
        return stack.top().first;
    }

    int getMin()
    {
        return stack.top().second;
    }
};