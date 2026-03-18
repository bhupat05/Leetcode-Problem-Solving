// Last updated: 3/18/2026, 2:21:12 PM
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> r(n, -1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < nums[i]; j++) {
                if ((j | (j + 1)) == nums[i]) {
                    r[i] = j;
                    break;  
                }
            }
        }
        return r;
    }
};
