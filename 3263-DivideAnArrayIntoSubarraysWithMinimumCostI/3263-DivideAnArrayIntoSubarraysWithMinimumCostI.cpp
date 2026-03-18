// Last updated: 3/18/2026, 2:21:43 PM
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        sort(nums.begin() + 1, nums.end());

        

        return nums[0] + nums[1] + nums[2];
    
        
    }
};