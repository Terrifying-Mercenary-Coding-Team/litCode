#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        unordered_map<int, int>::iterator it;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(nums[i]) == hash.end())
                hash[nums[i]] = 1;
            else
                hash[nums[i]]++;
        }
        int max;
        int cnt = 0;
        while (1) {
            max = 0;
            for (it = hash.begin(); it != hash.end(); it++) {
                if (it->second > max)
                    max = it->second;
            }
            for (it = hash.begin(); it != hash.end();) {
                if (it->second == max) {
                    ans.push_back(it->first);
                    it = hash.erase(it);
                    cnt++;
                    if (cnt == k)
                        break;
                }
                else
                    it++;
            }
            if (cnt == k)
                break;
        }
        max = 0;

        return ans;
    }
};

int main()
{
    vector<int> nums = { 1, 1, 1, 2, 2, 3 }, ans;
    int target = 2;
    Solution sol;
    ans = sol.topKFrequent(nums, target);
    for (int i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}