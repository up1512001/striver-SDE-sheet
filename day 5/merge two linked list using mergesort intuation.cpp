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

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *merged(ListNode *l1, ListNode *l2)
    {
        ListNode *p = l1->next, *q = l2, *x = l1;
        while (p != nullptr && q != nullptr)
        {
            if (p->val <= q->val)
            {
                x->next = p;
                p = p->next;
            }
            else
            {
                x->next = q;
                q = q->next;
            }
            x = x->next;
        }
        if (!p)
            x->next = q;
        else
            x->next = p;
        return l1;
    }

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1 && !list2)
            return nullptr;
        else if (!list1)
            return list2;
        else if (!list2)
            return list1;
        else if (list1->val <= list2->val)
        {
            return merged(list1, list2);
        }
        return merged(list2, list1);
    }
};

class Solution
{
public:
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode *result;
        if (l1 == NULL)
        {
            return l2;
        }
        if (l2 == NULL)
        {
            return l1;
        }
        if (l1->val <= l2->val)
        {
            result = l1;
            result->next = merge(l1->next, l2);
        }
        else
        {
            result = l2;
            result->next = merge(l1, l2->next);
        }
        return result;
    }
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *temp = merge(l1, l2);
        return temp;
    }
};
