#include <bits/stdc++.h>

using namespace std;

struct Node{
    int key;
    int value;
    Node *prev;
    Node *nxt;
    
    Node(): key(0), value(0), prev(nullptr), nxt(nullptr) {}
};

class LRUCache {
public:
    int size;
    int capacity;
    unordered_map<int,Node*> hash;
    Node *head,*tail;

    LRUCache(int capacity): size(0), capacity(capacity) {
        head = new Node();
        tail = new Node();
        head->nxt = tail;
        tail->prev = head;
    }
    
    void add_node(Node *node){
        node->prev = head;
        node->nxt = head->nxt;

        head->nxt->prev = node;
        head->nxt = node;
    }

    void remove_node(Node *node){
        Node *tmp = node->prev;

        tmp->nxt = node->nxt;
        node->nxt->prev = tmp;
    }

    void move_to_head(Node *node){
        remove_node(node);
        add_node(node);
    }

    Node* pop_tail(){
        Node *ret = tail->prev;
        remove_node(ret);
        return ret;
    }

    int get(int key){
        auto it = hash.find(key);
        if(it==hash.end())  return -1;
        Node *node = it->second;
        move_to_head(node);

        return node->value;
    }
    
    void put(int key, int value){
        auto it = hash.find(key);
        if(it!=hash.end()){
            Node *node = it->second;
            node->value = value;
            move_to_head(node);
            return;
        }
        Node *new_node = new Node();
        new_node->key = key;
        new_node->value = value;
        hash[key] = new_node;
        add_node(new_node);
        size++;
        if(size>capacity){
            Node *last = pop_tail();
            hash.erase(last->key);
            delete last;
            size--;
        }
    }
};

