#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int x, y;
        unordered_map<int, int> hash;
        vector<int> ans;
        int vsize = nums.size();
        for (int i = 0; i < vsize; i++) {
            hash[nums[i]] = i;
        }
        for (int i = 0; i < vsize; i++) {
            int diff = target - nums[i];
            if (hash.find(diff) != hash.end()) {
                if (hash.find(diff)->second == i)
                    continue;
                ans.push_back(i);
                ans.push_back(hash.find(diff)->second);
                return ans;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {2, 7, 11, 15}, ans;
    int target = 9;
    Solution sol;
    ans = sol.twoSum(nums, target);
    cout << ans[0] << " " <<ans[1] << endl;
    return 0;
}