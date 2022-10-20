#include <bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    vector<int> ans(temperatures.size(), 0);
    stack<int> stk;

    for (int i = 0; i < temperatures.size(); i++)
    {
        while (!stk.empty() && temperatures[i] > temperatures[stk.top()])
        {
            ans[stk.top()] = i - stk.top();
            stk.pop();
        }

        stk.push(i);
    }

    return ans;
}