#include <bits/stdc++.h>
using namespace std;

class KthLargest
{

private:
    int k;
    priority_queue<int> minHeap;

public:
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;

        for (int i = 0; i < nums.size(); i++) // creates a minHeap Priority queue
        {
            minHeap.push(nums[i] * (-1));
        }

        while (minHeap.size() > this->k) // the top element will always be the kth largest
        {
            minHeap.pop();
        }
    }

    int add(int val)
    {
        minHeap.push(val * (-1)); // pushes given value onto the heap

        if (minHeap.size() > k) // if the minHeap size is larger than k, pop top value off
        {
            minHeap.pop();
        }

        return minHeap.top() * (-1); // return the kth largest element
    }
};
