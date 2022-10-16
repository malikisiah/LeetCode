#include <bits/stdc++.h>

using namespace std;

bool checkInclusion(string s1, string s2)
{
    unordered_map<char, int> s1map;
    unordered_map<char, int> s2map;

    for (int k = 0; k < s1.size(); k++)
    {
        s1map[s1[k]]++;
    }

    int i = 0;

    for (int j = s1.size() - 1; j < s2.size(); j++)
    {

        int x = i;
        while (x <= j)
        {
            s2map[s2[x]]++;
            x++;
        }
        i++;

        if (s1map == s2map)
        {
            return true;
        }

        else
        {
            s2map.clear();
        }
    }

    return false;
}