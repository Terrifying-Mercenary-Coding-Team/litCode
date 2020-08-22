#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret=0,tmp=0,st=0;
        map<char,int> hash;
        for(int i=0;i<s.size();i++){
            if(hash.find(s[i])==hash.end()){
                hash[s[i]] = i;
                tmp++;
            }
            else{
                if(hash[s[i]]<st){
                    hash[s[i]] = i;
                    tmp++;
                }
                else{
                    ret = max(ret,tmp);
                    st = hash[s[i]]+1;
                    tmp = i-st+1;
                    hash[s[i]] = i;
                }
            }
        }
        return ret=max(ret,tmp);
    }
};

int main(){
    Solution *sol = new Solution();
    cout << sol->lengthOfLongestSubstring("abcabcbb") << endl;
    cout << sol->lengthOfLongestSubstring("bbbbb") << endl;
    cout << sol->lengthOfLongestSubstring("pwwkew") << endl;
    cout << sol->lengthOfLongestSubstring("dvdf") << endl;

    return 0;
}
