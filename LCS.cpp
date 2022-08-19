#include <iostream>
#include <algorithm>

using namespace std;

int LCS(string text1, string text2);

int main()
{

    printf("%d", LCS("abcde", "abc"));
}

int LCS(string text1, string text2)
{
    int m = text1.length();
    int n = text2.length();

    int table[m + 1][n + 1];
    int answer = 0;

    //

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            // first row and column will be 0
            if (i == 0 || j == 0)
            {
                table[i][j] = 0;
            }

            // if the strings at each index match
            else if (text1[i - 1] == text2[j - 1])
            {
                table[i][j] = (table[i - 1][j - 1] + 1);
            }
            // if the strings at each index don't match
            else
            {
                table[i][j] = max((table[i][j - 1]), (table[i - 1][j])); // returns the max length of subsequence at j-1 or i-1
            }
        }
    }

    return table[m][n];
}
