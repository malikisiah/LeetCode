#include <iostream>
#include <ctype.h>
#include <algorithm>
#include <cstring>
#include <cwctype>
using namespace std;

bool isPalindrom(string s);

int main()
{

    cout << isPalindrom("A man,  a plan,  a canal: Panama");
}

bool isPalindrom(string s)
{
    string str = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (iswalnum(s[i]) != 0)
        {
            str += s[i];
        }
    }

    transform(str.begin(), str.end(), str.begin(), ::toupper);

    for (int i = 0, j = str.size() - 1; i < j; i++, j--)
    {
        if (str[i] != str[j])
        {
            return false;
        }
    }

    return true;
}