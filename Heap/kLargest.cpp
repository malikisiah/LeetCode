int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int> pq;

    for (auto x : nums)
    {
        pq.push(x * -1);
    }

    while (pq.size() > k)
    {
        pq.pop();
    }

    return pq.top() * -1;
}