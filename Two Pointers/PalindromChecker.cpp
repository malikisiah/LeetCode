#include <iostream>
#include <ctype.h>
#include <algorithm>
#include <cstring>
#include <cwctype>
using namespace std;

bool isPalindrome(string s)
{
    string str = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (iswalnum(s[i]) != 0)
        {
            str += toupper(s[i]);
        }
    }

    string temp = str;

    reverse(str.begin(), str.end());

    if (temp == str)
    {
        return true;
    }

    return false;
}