#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ret=1;
        int n=wordList.size();
        int l=beginWord.size();

        unordered_map<string,bool> visited;
        unordered_map<string,vector<string>> hash;

        if(find(wordList.begin(),wordList.end(),endWord)==wordList.end())   return 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<l;j++){
                string tmp = wordList[i];
                tmp[j] = '*';
                hash[tmp].push_back(wordList[i]);
            }
        }
        queue<string> q;
        q.push(beginWord);
        visited[beginWord] = true;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                string cur=q.front();
                q.pop();
                if(cur==endWord) return ret;
                for(int j=0;j<l;j++){
                    string tmp=cur;
                    tmp[j] = '*';
                    for(string nxt: hash[tmp]){
                        if(visited.find(nxt)!=visited.end())    continue;
                        visited[nxt] = true;
                        q.push(nxt);
                    }
                }
            }
            ret++;
        }
        return 0;
    }
};

int main(){
    Solution *sol = new Solution;
    vector<string> args={"hot","dot","dog","lot","log","cog"};
    vector<string> args2={"hot","dot","dog","lot","log"};
    cout << sol->ladderLength("hit","cog",args) << endl;
    cout << sol->ladderLength("hit","cog",args2) << endl;
}
