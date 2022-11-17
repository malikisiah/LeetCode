#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *left = head;
    ListNode *right = head;
    ListNode *prev = NULL;

    if (head->next == NULL)
    {
        return NULL;
    }

    // setting right pointer

    while (n > 0)
    {
        right = right->next;
        n--;
    }

        if (right == NULL)
    {
        return head->next;
    }

    // left pointer will be node to remove
    while (right != NULL)
    {
        prev = left;
        left = left->next;
        right = right->next;
    }

    prev->next = left->next;
    left->next = NULL;

    return head;
}