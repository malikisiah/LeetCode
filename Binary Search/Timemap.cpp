#include <bits/stdc++.h>
using namespace std;

class TimeMap
{
public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        map[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        int low = 0;
        int high = map[key].size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (map.at(key)[mid].first == timestamp)
            {
                return map.at(key)[mid].second;
            }

            if (map.at(key)[mid].first < timestamp)
            {
                low = mid + 1;
            }

            if (map.at(key)[mid].first > timestamp)
            {
                high = mid - 1;
            }
        }

        if (high >= 0)
        {
            return map.at(key)[high].second;
        }

        return "";
    }

private:
    unordered_map<string, vector<pair<int, string>>> map;
};