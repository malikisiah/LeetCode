#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node *next;
};

bool hasCycle(Node *head);

int main()
{
    Node *l1 = new Node();
    Node *l2 = new Node();
    Node *l3 = new Node();
    Node *l4 = new Node();

    l1->val = 3;
    l2->val = 2;
    l3->val = 0;
    l4->val = -4;

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l2;


   cout <<  hasCycle(l1) << endl;;
}


bool hasCycle(Node* head){
    unordered_set<Node*>set;

    while(head != NULL){

        if(set.find(head) != set.end()){
            return true;
        }


        if (set.find(head) == set.end()){
            set.insert(head);
        }

        head = head->next;
    }

    return false;
}