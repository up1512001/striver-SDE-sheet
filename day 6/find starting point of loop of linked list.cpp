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



class Solution{
public:
    ListNode *detectCycle(ListNode *head){
        ListNode *p=head;
        unordered_set<ListNode *> st;
        while(p!=nullptr){
            if(st.find(p)!=st.end()){
                return p;
            }
            st.insert(p);
            p=p->next;
        }
        return nullptr;
    }
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
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
            {
                int x = 0;
                slow = head;
                while (slow != fast)
                {
                    x++;
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
