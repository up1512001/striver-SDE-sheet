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
    ListNode *getIntersectionNode(ListNode *headA,ListNode *headB){
        stack<ListNode*> s1,s2;
        ListNode *ret=nullptr;
        ret=headA;
        while(ret!=nullptr){
            s1.push(ret);
            ret = ret->next;
        }
        ret=headB;
        while(ret!=nullptr){
            s2.push(ret);
            ret = ret->next;
        }
        ret = nullptr;
        while(!s1.empty() && !s2.empty()){
            if(s1.top() == s2.top()){
                ret = s1.top();
                s1.pop();
                s2.pop();
            }else{
                break;
            }
        }
        return ret;
    }
};

// mine other approach is take int stack


// leetcode approach
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *p=headA,*q=headB;
        if(p==nullptr || q == nullptr) return nullptr;
        while(p!=nullptr && q!=nullptr && p!=q){
            p=p->next;
            q=q->next;
            if(p==q){
                return p;
            }
            if(p==nullptr){
                p=headB;
            }
            if(q==nullptr){
                q=headA;
            }
        }
        return p;        
    }
};



/*
1 2 3
        4 5 6 7
2 3 5 6


*/