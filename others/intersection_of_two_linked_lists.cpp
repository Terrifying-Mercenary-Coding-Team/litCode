#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode *,int> hash_a,hash_b;
        while(headA && headB){
            if(hash_b.find(headA)!=hash_b.end())    return headA;
            else{
                hash_a[headA] = 1;
                headA = headA->next;
            }
            if(hash_a.find(headB)!=hash_a.end())    return headB;
            else{
                hash_b[headB] = 1;
                headB = headB->next;
            }
        }
        while(headA){
            if(hash_b.find(headA)!=hash_b.end())    return headA;
            headA = headA->next;
        }
        while(headB){
            if(hash_a.find(headB)!=hash_a.end())    return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};
