#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *bottom;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) , bottom(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next), bottom(nullptr) {}
    ListNode(int x,ListNode *next,ListNode *bottom) : val(x) , next(next) , bottom(bottom) {}
};


class Solution{
public:


    ListNode *mergeTwoLinkedList(ListNode *l1,ListNode *l2){
        ListNode *p = new ListNode(0);
        ListNode *q = p->next;
        while(l1!=nullptr && l2!=nullptr){
            if(l1->val <= l2->val){
                p->bottom = l1;
                p=p->bottom;
                l1 = l1->bottom;
            }else{
                p->bottom = l2;
                p = p->bottom;
                l2 = l2->bottom;
            }
        }
        
        /*
        while(l1!=nullptr){
            p->bottom = l1;
            p = p->bottom;
            l1 = l1->bottom;
        }
        while(l2!=nullptr){
            p->bottom = l2;
            p = p->bottom;
            l2 = l2->bottom;
        }
        */
        // above will be reduce like

        if(l1) p->bottom = l1;
        else if (l2) p->bottom = l2;

        return q;
    }

    ListNode *flattenLinkedList(ListNode *head){
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        head->next = flattenLinkedList(head->next);

        head = mergeTwoLinkedList(head,head->next);
    }  
};