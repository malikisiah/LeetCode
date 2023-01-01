#include <bits/stdc++.h>
using namespace std;

vector<string> letterCombinations(string digits)
{
    vector<string> result;

    unordered_map<char, string> map = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    string curr = "";

    return result;
}

void dfs(string digits, int idx, unordered_map<char, string> &map, string &curr, vector<string> result)
{

    if (curr.size() == digits.size())
    {
        result.push_back(curr);
        return;
    }

    string str = map[digits[idx]]; // a single char that maps to a string

    for (int i = idx; i < digits.size(); i++)
    {
        curr.push_back(digits[i]);
        dfs(digits, i + 1, map, curr, result);
        curr.pop_back();
    }
}