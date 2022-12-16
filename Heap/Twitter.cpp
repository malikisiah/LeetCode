#include <bits/stdc++.h>
using namespace std;

class Twitter
{
public:
    Twitter()
    {
    }

    void postTweet(int userId, int tweetId)
    {
        tweetList.push_back({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        int count = 10;
        vector<int> result;

        for (int i = tweetList.size() - 1; i >= 0; i--)
        {
            if (count == 0)
            {
                break;
            }

            int followingId = tweetList[i].first;
            int tweetId = tweetList[i].second;

            unordered_set<int> following = hMap[userId];

            if (following.find(followingId) != following.end() || followingId == userId)
            {
                result.push_back(tweetId);
                count--;
            }
        }

        return result;
    }

    void follow(int followerId, int followeeId)
    {
        hMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        hMap[followerId].erase(followeeId);
    }

private:
    unordered_map<int, unordered_set<int>> hMap;
    vector<pair<int, int>> tweetList;
};