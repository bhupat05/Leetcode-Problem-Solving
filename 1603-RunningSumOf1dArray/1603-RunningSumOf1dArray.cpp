// Last updated: 3/18/2026, 2:24:17 PM
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        result[0] = nums[0];

        for(int i = 1; i < n; i++) {
            result[i] = result[i - 1] + nums[i];
        }
        return result;
    }
};