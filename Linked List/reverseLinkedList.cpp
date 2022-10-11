#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct Node
{
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

Node* reverseList(Node* head);

int main(){
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;
    Node *fourth = NULL;
    Node *fifth = NULL;

    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();
    fifth = new Node();

    head->val = 1;
    head->next = second;

    second->val = 2;
    second->next = third;

    third->val = 3;
    third->next = fourth;

    fourth->val = 4;
    fourth->next = fifth;

    fifth->val = 5;
    fifth->next= NULL;

    reverseList(head);


}

Node* reverseList(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL){
        next = curr->next;
        curr->next = prev;

        prev=curr;
        curr=next;

    }

    head = prev;

    return head;



}
