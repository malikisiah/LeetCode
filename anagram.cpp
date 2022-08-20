#include <iostream>
#include <map>

using namespace std;

bool isAnagram(string s, string t);

int main()
{

    string s = "rat";
    string t = "car";

    if (isAnagram(s,t) == false){
        printf("Not an anagram\n");
    }

    else{
        printf("Is an anagram\n");
    }
}

bool isAnagram(string s, string t)
{
    map<char, int> s_map;
    map<char, int> t_map;

    if (s.size() != t.size())
    {
        return false;
    }

    for (int i = 0; i < s.size(); i++)
    {

        if (s_map.find(s[i]) == s_map.end())
        {
            s_map.insert({s[i], 1});
        }

        else
        {
            s_map[s[i]]++;
        }
    }

    for (int i = 0; i < t.size(); i++)
    {

        if (t_map.find(t[i]) == t_map.end())
        {
            t_map.insert({t[i], 1});
        }

        else
        {
            t_map[t[i]]++;
        }
    }

    if (s_map == t_map){
        return true;
    }

    return false;
}