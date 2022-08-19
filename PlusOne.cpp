#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> plusOne(vector<int> &digits);

int main()
{
    vector<int> number{9, 9, 9};

    printf("Input: ");
    for (int x : number)
    {
        printf("%d", x);
    }

    printf("\n");

    plusOne(number);

    printf("Output: ");
    for (int x : number)
    {
        printf("%d", x);
    }
}

vector<int> plusOne(vector<int> &digits)
{

    for (int i = digits.size() - 1; i >= 0; i--)
    {
        if (digits[i] == 9)
        {
            digits[i] = 0;
        }
        else
        {
            digits[i] += 1;
            return digits;
        }
    }

    digits.push_back(1);
    reverse(digits.begin(), digits.end());
    return digits;
}