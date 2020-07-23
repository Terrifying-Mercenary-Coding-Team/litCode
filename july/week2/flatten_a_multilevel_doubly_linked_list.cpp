#include <iostream>
#include <stack>

using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int n): val(n), prev(nullptr), next(nullptr), child(nullptr) {};
};

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return nullptr;
        Node* cur=head;
        while(cur){
            if(cur->child){
                Node *nxt = cur->next;
                Node *child = flatten(cur->child);
                cur->child = nullptr;
                cur->next = child;
                child->prev = cur;
                Node *fin = child;
                while(fin->next)    fin = fin->next;
                fin->next = nxt;
                if(nxt) nxt->prev = fin;
            }
            cur = cur->next;
        }
        return head;
    }
};

int main(){
    Node root(1),second(2),third(3);
    root.next = &second;
    root.child = &third;
    Solution sol;

    for(Node *ret=sol.flatten(&root);ret;ret=ret->next)  cout << ret->val << " " << endl; 

    return 0;
}
