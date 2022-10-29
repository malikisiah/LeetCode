#include <bits/stdc++.h>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{

    int lowRow = 0;
    int highRow = matrix.size() - 1;

    while (lowRow < highRow)
    {
        int mid = lowRow + (highRow - lowRow) / 2;

        if (matrix[mid][0] == target)
        {
            return true;
        }

        if (matrix[mid][0] < target && target < matrix[mid + 1][0])
        {
            lowRow = mid;
            break;
        }

        if (matrix[mid][0] < target)
        {
            lowRow = mid + 1;
        }

        else
        {
            highRow = mid - 1;
        }
    }

    int low = 0;
    int high = matrix[0].size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (matrix[lowRow][mid] == target)
        {
            return true;
        }

        if (matrix[lowRow][mid] < target)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }

    return false;
}