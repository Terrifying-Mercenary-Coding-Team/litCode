#include <bits/stdc++.h>

using namespace std;

struct Trie{
    Trie *node[26];
    vector<int> inds;

    Trie(){
        fill(node,node+26,nullptr);
    }
    ~Trie(){
        for(int i=0;i<26;i++) if(node[i]) delete node[i];
    }
    void build(string target, int pos, int ind){
        if(pos==target.size())   return;
        int cur=target[pos]-'a';
        if(!node[cur])    node[cur] = new Trie;
        inds.push_back(ind);
        node[cur]->build(target,pos+1,ind);
    }
};

class Solution {
public:
    vector<vector<string>> ret;
    int word_size,total_size;
    Trie *root = new Trie;
   
    void backtrack(vector<string>& words, vector<string>& cur, int pos){
        if(pos==word_size){
            ret.push_back(cur);
            return;
        }
        string prefix="";
        for(int i=0;i<cur.size();i++)   prefix += cur[i][pos];
        Trie *tmp = root;
        for(int i=0;i<prefix.size();i++){
            if(tmp->node[prefix[i]-'a'])    tmp = tmp->node[prefix[i]-'a'];
            else    return;
        }

        for(int ind: tmp->inds){
            cur.push_back(words[ind]);
            backtrack(words,cur,pos+1);
            cur.pop_back();
        }
    }
    vector<vector<string>> wordSquares(vector<string>& words) {
        word_size = words[0].size();
        total_size = words.size();

        for(int i=0;i<total_size;i++)   root->build(words[i],0,i);

        for(int i=0;i<total_size;i++){
            vector<string> tmp;
            tmp.push_back(words[i]);
            backtrack(words,tmp,1);
        }
        return ret;
    }
};
