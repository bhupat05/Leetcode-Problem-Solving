// Last updated: 3/18/2026, 2:25:29 PM
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> result;
        int numi = 0;

        for(int i = 0; i < n; i++) {
            numi = ((numi << 1) + nums[i]) % 5;
            result.push_back(numi == 0);
        }

        return result;
    }
};