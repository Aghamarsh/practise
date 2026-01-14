/*
    Author: Aghamarsh Varanasi
    Date: Jan 6, 2026
*/

#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int> mp;
       for(int i=0; i<nums.size(); i++){
         int tar= target-nums[i];
        if(mp.find(tar)!=mp.end()) {
            return {mp[tar],i};
        }
        mp[nums[i]]=i;
       }
       return {};
    }
};

int main () {
    Solution s;
    vector<int> nums{2, 7, 11, 15};
    int target = 9;
    vector<int> indices = s.twoSum(nums, target);
    cout << "[ "<< indices[0] << ", " << indices[1] <<" ]\n";
}