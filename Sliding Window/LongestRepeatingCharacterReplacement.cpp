#include <bits/stdc++.h>

using namespace std;

int characterReplacement(string s, int k)
{
    int maxLength = 0;

    unordered_map<char, int> map;
    int left = 0;
    int length = 0;

    int i = 0;

    for (int j = 0; j < s.size(); j++)
    {

        int maxFreq = 0;
        if (map.find(s[j]) == map.end())
        {
            map.insert({s[j], 1});
        }

        else
        {
            map[s[j]]++;
        }

        for (auto x : map)
        {
            maxFreq = max(maxFreq, x.second);
        }
        // if window is invalid
        while ((j - i + 1) - maxFreq > k)
        {
            map[s[i]]--;

            i++;
        }

        maxLength = max(maxLength, j - i + 1);
    }

    return maxLength;
}