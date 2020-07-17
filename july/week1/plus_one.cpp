#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ret;
        bool carry=true;
        for(int i=digits.size()-1;i>=0;i--){
            int tmp = carry ? digits[i] + 1 : digits[i];
            if(tmp>=10){
                tmp -= 10;
                carry = true;
            }
            else    carry = false;
            ret.push_back(tmp);
        }
        if(carry)   ret.push_back(1);
        reverse(ret.begin(),ret.end());
        return ret;
    }
};

int main(){
    Solution sol;
    vector<int> test = {9};
    vector<int> test_2 = {4,3,2,1};
    vector<int> ret = sol.plusOne(test);
    vector<int> ret_2 = sol.plusOne(test_2);

    for(int e: ret) cout << e << " ";
    cout << endl;
    for(int e: ret_2) cout << e << " ";
    cout << endl;

    return 0;
}
