// https://www.youtube.com/watch?v=VNf6VynfpdM
// for revision

#include<bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;
        Node *p = head;
        while (p != nullptr)
        {
            Node *temp = new Node(p->val);
            temp->next = p->next;
            p->next = temp;
            p = temp->next;
        }
        Node *ret = head->next;
        p = head;
        while (p != nullptr)
        {
            if (p->random)
                p->next->random = p->random->next;
            p = p->next->next;
            // q=q->next->next;
        }
        p = head;
        Node *q = head->next;
        Node *n = p;
        while (p != nullptr && q != nullptr)
        {
            // n=p->next->next;
            n = q->next;
            p->next = q->next;
            if (n)
                q->next = n->next;
            p = p->next;
            q = q->next;
        }
        return ret;
    }
};




