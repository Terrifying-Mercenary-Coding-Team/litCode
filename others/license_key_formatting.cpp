#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int cnt=0;
        string ret="";
        for(int i=S.size()-1;i>=0;i--){
            if(S[i]=='-')   continue;
            if('a'<=S[i] && S[i]<='z')  ret += char('A'+(S[i]-'a'));
            else    ret += S[i];
            if(++cnt==K){
                cnt = 0;
                ret += "-";
            }
        }
        if(ret.empty()) return ret;
        if(!cnt)    ret.pop_back();
        reverse(ret.begin(),ret.end());
        return ret;
    }
};

int main(){
    Solution *s = new Solution();
    cout << s->licenseKeyFormatting("5F3Z-2e-9-w",4) << endl;
    cout << s->licenseKeyFormatting("2-5g-3-J",2) << endl;
    cout << s->licenseKeyFormatting("2-4A0r7-4k",4) << endl;
    cout << s->licenseKeyFormatting("---",3) << endl;

    return 0;
}
