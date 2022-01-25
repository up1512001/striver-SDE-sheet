#include<bits/stdc++.h>

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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head)
            return nullptr;
        else if (head->next == nullptr)
            return nullptr;
        else if (head->next->next == nullptr)
        {
            if (n == 1)
            {
                return new ListNode(head->val);
            }
            return new ListNode(head->next->val);
        }
        int len = 0, x = 1;
        ListNode *p = head;
        while (p != nullptr)
        {
            p = p->next;
            len++;
        }
        p = head;
        if (len - n == 0)
            return head->next;
        while (x != (len - n))
        {
            p = p->next;
            x++;
        }
        p->next = p->next->next;
        return head;
    }
};