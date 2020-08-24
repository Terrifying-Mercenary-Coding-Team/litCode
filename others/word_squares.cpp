#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> ret;
    int word_size,total_size;
    unordered_map<string,unordered_set<string>> hash;
   
    void backtrack(vector<string>& words, vector<string>& cur, int pos){
        if(pos==word_size){
            ret.push_back(cur);
            return;
        }
        string prefix="";
        for(int i=0;i<cur.size();i++)   prefix += cur[i][pos];
        for(string tar: hash[prefix]){
            cur.push_back(tar);
            backtrack(words,cur,pos+1);
            cur.pop_back();
        }
    }
    vector<vector<string>> wordSquares(vector<string>& words) {
        word_size = words[0].size();
        total_size = words.size();
        for(string word: words){
            string tmp="";
            for(int i=0;i<word_size;i++){
                tmp += word[i];
                hash[tmp].insert(word);
            }
        }

        for(int i=0;i<total_size;i++){
            vector<string> tmp;
            tmp.push_back(words[i]);
            backtrack(words,tmp,1);
        }
        return ret;
    }
};
