// Last updated: 3/18/2026, 2:21:20 PM
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] % 3 != 0) count++;
        }
        return count;
    }
};