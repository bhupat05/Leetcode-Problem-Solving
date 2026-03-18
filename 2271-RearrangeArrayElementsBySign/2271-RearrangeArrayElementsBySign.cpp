// Last updated: 3/18/2026, 2:22:58 PM
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int l = 0;
        int r = 1;
        int k = 0;

        int n = nums.size();
        vector<int> v(n);

        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                v[l] = nums[i]; 
                l += 2;
            } else {
                v[r] = nums[i];
                r = r + 2;
            }
        }
        return v;
    }
};