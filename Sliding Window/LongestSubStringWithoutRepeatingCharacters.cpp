#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    int maxLength = 0;
    unordered_set<char> set;

    int i = 0;

    for (int j = 0; j < s.size(); j++)
    {

        while (set.find(s[j]) != set.end())
        {
            set.erase(s[i]);
            i++;
        }

        set.insert(s[j]);

        int n = set.size();
        maxLength = max(maxLength, n);
    }

    return maxLength;
}