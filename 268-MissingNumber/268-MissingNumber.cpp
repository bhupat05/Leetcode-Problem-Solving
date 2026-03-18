// Last updated: 3/18/2026, 2:28:26 PM
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 1; i <= n; i++){
            ans ^= i;
        }

        for(int i = 0; i < nums.size(); i++){
            ans ^= nums[i];
        }
        return ans;
    }
};