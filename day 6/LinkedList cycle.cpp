#include<bits/stdc++.h>

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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head || !head->next)
            return false;
        ListNode *f = head, *s = head;
        while (f != nullptr && f->next != nullptr)
        {

            f = f->next->next;
            s = s->next;
            if (f == s)
            {
                return true;
            }
        }
        return false;
    }
};