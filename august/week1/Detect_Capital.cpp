#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word[0] >= 'A' && word[0] <= 'Z') {
            bool check = true;
            for (int i = 1; i < word.length(); i++) {
                if (word[i] < 'A' || word[i] > 'Z')
                    check = false;
            }
            if (check == true)
                return true;
            check = true;
            for (int i = 1; i < word.length(); i++) {
                if (word[i] < 'a' || word[i] > 'z')
                    check = false;
            }
            return check;
        }
        else if (word[0] >= 'a' && word[0] <= 'z') {
            bool check = true;
            for (int i = 1; i < word.length(); i++) {
                if (word[i] < 'a' || word[i] > 'z')
                    check = false;
            }
            return check;
        }
        else
            return false;
    }
};

int main()
{
    string word = "USA";
    Solution sol;
    bool ans = sol.detectCapitalUse(word);
    printf(ans ? "true\n" : "false\n");
    return 0;
}