#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
  
  // mine approach
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
            return head;
        // else if(head->next->next==nullptr){
        //     if(k%2==0){
        //         return head;
        //     }else{
        //         head->next->next = head;
        //         ListNode *t = head->next;
        //         head->next = nullptr;
        //         head = t;
        //         return t;
        //     }
        // }
        int cnt = 0;
        ListNode *p = head, *q = head, *i = head;
        while (p != nullptr)
        {
            cnt++;
            p = p->next;
        }
        p = head;
        k = k % cnt;
        if (k == 0)
            return head;
        cnt = cnt - k;
        while (cnt--)
        {
            q = p;
            p = p->next;
        }
        head = p;
        q->next = nullptr;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = i;
        // cout<<i->val<<"\n";
        return head;
    }
};



// other approach

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || k <= 0)
        {
            return head;
        }

        //find the length of List
        int len = 1;
        ListNode *p = head;
        while (p->next != NULL)
        {
            p = p->next;
            len++;
        }
        if (k % len == 0)
            return head;
        //connect the tail to head
        p->next = head;
        //find the left place (take care the case - k > len)
        k = len - k % len;

        //find the place
        for (int i = 0; i < k; i++)
        {
            p = p->next;
        }

        //break the list
        head = p->next;
        p->next = NULL;

        return head;
    }
};