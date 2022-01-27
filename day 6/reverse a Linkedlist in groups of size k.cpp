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

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        stack<int> s;
        ListNode *p = head, *q = head;
        while (p != nullptr)
        {
            if (s.size() == k)
            {
                while (!s.empty())
                {
                    q->val = s.top();
                    s.pop();
                    q = q->next;
                }
            }
            s.push(p->val);
            p = p->next;
        }
        if (s.size() == k)
        {
            while (!s.empty())
            {
                q->val = s.top();
                s.pop();
                q = q->next;
            }
        }
        return head;
    }
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        vector<int> a;
        int t = k;
        ListNode *p = head, *q = head;
        while (p != nullptr)
        {
            q = p;
            t = k;
            while (t-- && p != nullptr)
            {
                a.push_back(p->val);
                p = p->next;
            }
            if (a.size() < k)
                break;
            // for(int i=0;i<a.size();i++)cout<<a[i]<<" ";
            int i = a.size() - 1;
            while (q != p)
            {
                q->val = a[i];
                i--;
                q = q->next;
            }
            a.clear();
        }
        return head;
    }
};