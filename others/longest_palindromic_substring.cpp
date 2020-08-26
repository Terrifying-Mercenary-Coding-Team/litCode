#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(!s.size())    return "";
        int ret=1;
        string rets = "";
        rets += s[0];
        for(int i=0;i<s.size();i++){
            int left=i-1,right=i+1;
            string tmp="";
            tmp += s[i];
            while(0<=left&&right<s.size()){
                tmp += s[right];
                if(s[left--]!=s[right++])   break;
                int cnt=right-left+1;
                if(cnt>ret){
                    ret = cnt;
                    rets = tmp;
                }
            }
            left=i,right=i+1;
            tmp="";
            while(0<=left&&right<s.size()){
                tmp += s[right];
                if(s[left--]!=s[right++])   break;
                int cnt=right-left+1;
                if(cnt>ret){
                    ret = cnt;
                    rets = tmp;
                }
            }
        }
        if(ret==1)  return rets;
        int st=ret%2;
        string left="";
        for(int i=st;i<rets.size();i++)  left += rets[i];
        reverse(left.begin(),left.end());
        rets = left+rets;

        return rets;
    }
};
