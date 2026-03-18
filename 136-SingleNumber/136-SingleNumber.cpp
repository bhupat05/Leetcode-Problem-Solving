// Last updated: 3/18/2026, 2:30:06 PM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int x = nums[0];
        for(int i=1; i<n; i++){
            x ^= nums[i];
        }
        return x;
    }
};