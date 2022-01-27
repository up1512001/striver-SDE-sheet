#include<bits/stdc++.h>
using namespace std;
#pragma region INDIA

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    bool isPalindrome(ListNode* head){
        vector<int> t;
        ListNode *p=head;
        while(p!=nullptr){
            t.emplace_back(p->val);
            p=p->next;
        }
        for(int i=0,j=t.size()-1;i<j;i++,j--){
            if(t[i]!=t[j]){
                return false;
            }
        }
        return true;
    }
};



// other approach O(1) space

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *p=head,*q=head;
        while(q!=nullptr && q->next != nullptr){
            p=p->next;
            q=q->next->next;
        }
        if(q==nullptr){
            q=p;
        }else{
            q=p->next;
        }
        ListNode *curr=q,*prev=nullptr,*next=curr;
        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        p=head,q=prev;
        while((p!=nullptr && q!=nullptr)){
            if(p->val != q->val) return false;
            p=p->next;
            q=q->next;
        }
        return true;
    }
};
