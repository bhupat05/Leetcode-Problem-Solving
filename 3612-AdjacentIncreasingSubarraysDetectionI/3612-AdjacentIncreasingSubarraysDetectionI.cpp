// Last updated: 3/18/2026, 2:21:07 PM
class Solution {
public:
    bool check(vector<int>& nums, int s, int k){
        for(int i = s; i < s + k - 1; i++){
            if(nums[i] >= nums[i + 1]) return false;
        }
        return true;
    } 
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        if(n < 2 * k) return false;
        if(k == 1) return true;

        for(int i = 0; i <= n - 2 * k; i++){
            if(check(nums, i, k) && check(nums, i + k, k)) return true;
        }
        return false;
    }
};