#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

void reorderList(ListNode *head)
{
    if (head->next == NULL)
    {
        return;
    }

    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = NULL;

    while (fast != NULL && fast->next != NULL)
    {

        prev = slow;
        fast = fast->next->next;
        slow = slow->next;
    }

    prev->next = NULL;

    ListNode *l1 = head;
    ListNode *l2 = reverseList(slow);

    merge(l1, l2);
}

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev;
}

void merge(ListNode *l1, ListNode *l2)
{
    while (l1 != NULL)
    {
        ListNode *p1 = l1->next;
        ListNode *p2 = l2->next;

        l1->next = l2;
        if (p1 == NULL)
        {

            break;
        }

        l2->next = p1;

        l1 = p1;
        l2 = p2;
    }
}