#include <bits/stdc++.h>

using namespace std;

int evalRPN(vector<string> &tokens)
{
    stack<long long int> stack;

    for (int i = 0; i < tokens.size(); i++)
    {
        string token = tokens[i];

        if (token.size() > 1 || isdigit(token[0]))
        {
            stack.push(stoi(token));
        }

        else
        {
            long long int op1 = stack.top();
            stack.pop();
            long long int op2 = stack.top();
            stack.pop();

            stack.push(evaluate(op1, op2, token));
        }
    }

    return stack.top();
}

int evaluate(long long int op1, long long int op2, string op)
{
    if (op == "+")
    {
        return op1 + op2;
    }

    else if (op == "-")
    {
        return op1 - op2;
    }

    else if (op == "*")
    {
        return op1 * op2;
    }

    else
    {
        return op1 / op2;
    }
}