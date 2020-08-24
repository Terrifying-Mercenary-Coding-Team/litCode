#include <bits/stdc++.h>

using namespace std;

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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ret = new ListNode;
        ListNode *cur=ret;
        int carry=0;

        while(l1 && l2){
            cur->val = (l1->val+l2->val+carry)%10;
            carry = (l1->val+l2->val+carry)/10;
            l1 = l1->next;
            l2 = l2->next;
            if(l1 && l2){
                cur->next = new ListNode;
                cur = cur->next;
            }
        }
        while(l1){
            cur->next = new ListNode;
            cur = cur->next;
            cur->val = (l1->val+carry)%10;
            carry = (l1->val+carry)/10;
            l1 = l1->next;
        }
        while(l2){
            cur->next = new ListNode;
            cur = cur->next;
            cur->val = (l2->val+carry)%10;
            carry = (l2->val+carry)/10;
            l2 = l2->next;
        }
        if(carry){
            cur->next = new ListNode;
            cur->next->val = 1;
        }
        
        return ret;
    }
};
