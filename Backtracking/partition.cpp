#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> partition(string s)
{
    vector<vector<string>> result;
    vector<string> curr;

    dfs(s, 0, curr, result);
    return result;
}

void dfs(string s, int idx, vector<string> &curr, vector<vector<string>> &result)
{
    if (idx == s.size())
    {
        result.push_back(curr);
        return;
    }

    for (int i = idx; i < s.size(); i++)
    {
        if (isPalindrome(s, idx, i))
        {
            string str = s.substr(idx, i - idx + 1);
            curr.push_back(str);
            dfs(s, i + 1, curr, result);
            curr.pop_back();
        }
    }
}

bool isPalindrome(string s, int left, int right)
{

    while (left < right)
    {
        if (s[left] != s[right])
        {
            return false;
        }
        left++;
        right--;
    }

    return true;
}