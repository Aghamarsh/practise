/*
    Author: Aghamarsh Varanasi
    Date: Jan 11, 2026
*/
#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int curr = nums[0];

        for (int itr = 1; itr < nums.size(); itr++) {
            curr = max(nums[itr], (curr + nums[itr]));
            ans = max(ans, curr);
        }

        return ans;
    }
};

int main () {
    Solution s;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int max = s.maxSubArray(nums);
    cout << max << "\n";
}