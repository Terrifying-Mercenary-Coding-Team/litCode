#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        while(!s.empty() && s.back()==' ')
            s.pop_back();
        int blank;
        if ((blank = s.find(' '))==-1)
            return s;
        string word = s.substr(0,blank);
        string words = s.substr(blank);
        if (words.length()<=1)
            return word;
        words = words.substr(1);
        if (word.empty())
            return reverseWords(words);
        return reverseWords(words) + " " + word;
    }
};

int main(){
    Solution sol;
    string input;
    getline(cin,input);
    cout << sol.reverseWords(input) << endl;
}
