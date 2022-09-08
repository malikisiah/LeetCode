#include <bits/stdc++.h>

using namespace std;

int reverse(int x);

int main()
{
    int x = -123;

    cout << reverse(x) << endl;
}

int reverse(int x)
{
    string str = to_string(abs(x));
    string new_str = "";

    for (int i = str.size() - 1; i >= 0; i--)
    {
        new_str += str[i];
    }

    try
    {
        int ans = stoi(new_str);

        if (ans >= INT_MAX || ans <= INT_MIN){
            throw (out_of_range("blah"));
        }

        if (x < 0)
    {
        return ans * -1;
    }

    return ans;
    }

    catch (out_of_range){
        return 0;
    }


}