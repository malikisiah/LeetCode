#include <ctype.h>
#include <iostream>
#include <algorithm>

using namespace std;

string reverseOnlyLetters(string s);

int main()
{

    string s = "a-bC-dEf-ghIj";

    cout << s << endl;

    cout << reverseOnlyLetters(s) << endl;
}

string reverseOnlyLetters(string s)
{

    int i = 0;
    int j = s.size() - 1;
    char temp = ' ';

    while (i < j)
    {

        if (isalpha(s[i]) != 0 && isalpha(s[j]) != 0)
        {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }

        else if (isalpha(s[i]) == 0)
        {
            i++;
        }

        else
        {
            j--;
        }
    }

    return s;
}