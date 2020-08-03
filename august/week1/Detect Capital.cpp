#include<iostream>
#include<string.h>

using namespace std;

class Solution {
public:
    bool isLittle(string word){
        for (char& c : word){
            if (c<97 || c>122){
                return false;
            }
        }
        return true;
    }
    bool isCapital(string word){
        for (char& c : word){
            if (c<65 || c>90){
                return false;
            }
        }
        return true;
    }
    bool detectCapitalUse(string word,bool FirstIsCap){
        if (FirstIsCap){
            return isCapital(word) || isLittle(word);
        }else{
            return isLittle(word);
        }
    }
    bool detectCapitalUse(string word) {
        if (word.length()==0) return true;
        char c = word.at(0);
        if (c<65 || c>90){
            return detectCapitalUse(word.substr(1),false);
        }
        return detectCapitalUse(word.substr(1),true);
    }
};

int main()
{
	Solution s;

	string word[3] = { "USA","FlaG","Google" };

	for (int i = 0; i < 3; i++)
	{
		if (s.detectCapitalUse(word[i])) cout << "True\n";
		else cout << "No\n";
	}
}