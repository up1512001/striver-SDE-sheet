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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        ListNode *p = l1, *q = l2, *x = new ListNode(0), *y = x, *z = nullptr;
        while (p != nullptr || q != nullptr)
        {
            if (!p)
            {
                int t = q->val + carry;
                x->val = t % 10;
                carry = t / 10;
                z = x;
                x->next = new ListNode(0);
                x = x->next;
                q = q->next;
            }
            else if (!q)
            {
                int t = p->val + carry;
                x->val = t % 10;
                carry = t / 10;
                z = x;
                x->next = new ListNode(0);
                x = x->next;
                p = p->next;
            }
            else
            {
                int t = p->val + q->val + carry;
                x->val = t % 10;
                carry = t / 10;
                z = x;
                x->next = new ListNode(0);
                x = x->next;
                p = p->next;
                q = q->next;
            }
        }
        if (carry != 0)
        {
            x->val = carry;
        }
        else
        {
            z->next = nullptr;
        }
        return y;
    }
};



// striver approach
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        int carry = 0;
        while ((l1 != NULL || l2 != NULL) || carry)
        {
            int sum = 0;
            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;
            carry = sum / 10;
            ListNode *node = new ListNode(sum % 10);
            temp->next = node;
            temp = temp->next;
        }
        return dummy->next;
    }
};