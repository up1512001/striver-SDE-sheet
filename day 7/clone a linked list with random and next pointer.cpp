// https://www.youtube.com/watch?v=VNf6VynfpdM
// for revision

#include<bits/stdc++.h>
using namespace std;

// brute force will be O(N + N) and O(N)
//  create unordered_map<int,pair<Node*,Node*>> mp;


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



// other approach
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

class Solution
{
public:
    void dfs(Node *head)
    {
        Node *p = head;
        while (p != nullptr)
        {
            cout << p->val << " ";
            p = p->next;
        }
    }
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return head;

        Node *temp = head;

        //creates mapping of cloned list using original list
        while (temp)
        {
            Node *newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }

        //assigning random pointers
        temp = head;
        while (temp)
        {
            if (temp->random)
            {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        //restore the original linked list
        Node *newHead = head->next;
        Node *temp2 = head->next;
        temp = head;

        while (temp && temp2)
        {
            Node *currN = temp2->next;
            temp->next = currN;
            if (currN)
            {
                temp2->next = currN->next;
            }
            temp = temp->next;
            temp2 = temp2->next;
        }
        // dfs(newHead);
        return newHead;
    }
};
