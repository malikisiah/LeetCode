#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node *next;
};

Node *merge(Node *l1, Node *l2);

int main()
{
    Node *l1 = new Node();
    Node *l2 = new Node();
    Node *l3 = new Node();

    Node *m1 = new Node();
    Node *m2 = new Node();
    Node *m3 = new Node();

    l1->val = 1;
    l1->next = l2;

    l2->val = 2;
    l2->next = l3;

    l3->val = 4;

    m1->val = 1;
    m1->next = m2;

    m2->val = 3;
    m2->next = m3;

    m3->val = 4;

   Node* merged = new Node();

   merged =  merge(l1, m1);


   while (merged != NULL){
    cout << merged->val << " ";
    merged = merged->next;
   }
   cout << endl;
}

Node *merge(Node *l1, Node *l2)
{
    Node *head = new Node();

    Node *tail = head;

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val < l2->val)
        {
            tail->next = l1;
            l1 = l1->next;
        }

        else
        {
            tail->next = l2;
            l2 = l2->next;
        }

        tail = tail->next;
    }

    if (l1 == NULL)
    {
        tail->next = l2;
    }
    else if (l2 == NULL)
    {
        tail->next = l1;
    }

    return head->next;
}
