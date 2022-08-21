#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s);

int main()
{
    string s = "()[]{}";

    isValid(s);
}

bool isValid(string s)
{

    stack<char> stack;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') // if opening bracket is found, place on stack
        {
            stack.push(s[i]);
        }

        switch (s[i])
        {
        case ')':
            if (stack.top() != '(')
            {
                return false;
            }
            stack.pop();
            break;

        case ']':
            if (stack.top() != '[')
            {
                return false;
            }
            stack.pop();
            break;

        case '}':
            if (stack.top() != '{')
            {
                return false;
            }
            stack.pop();
            break;
        }
    }

    return stack.empty();
}