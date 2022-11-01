#include <bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int> &piles, int h)
{
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
    int ans = 0;

    int k = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (goBanannas(piles, mid, h) <= h)
        {
            high = mid - 1;
            k = min(k, mid);
        }

        else
        {
            low = mid + 1;
        }
    }

    return k;
}

long int goBanannas(vector<int> &piles, int k, int h)
{
    long int sum = 0;
    for (int i = 0; i < piles.size(); i++)
    {

        sum += ceil((double)piles[i] / k);
    }

    return sum;
}