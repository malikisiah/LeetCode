#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{

    ListNode *dummy = new ListNode();
    ListNode *l3 = dummy;
    int cry = 0;

    while (l1 != NULL || l2 != NULL)
    {
        int val1 = (l1 != NULL) ? l1->val : 0;
        int val2 = (l2 != NULL) ? l2->val : 0;
        int sum = val1 + val2 + cry;
        l3->next = new ListNode(sum % 10);

        cry = sum / 10;

        if (l1 != NULL)
        {
            l1 = l1->next;
        }

        if (l2 != NULL)
        {
            l2 = l2->next;
        }

        l3 = l3->next;
    }

    if (cry == 1)
    {
        l3->next = new ListNode(1);
    }

    return dummy->next;
}