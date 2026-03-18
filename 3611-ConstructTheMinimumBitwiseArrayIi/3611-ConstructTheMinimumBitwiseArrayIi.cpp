// Last updated: 3/18/2026, 2:21:09 PM
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int n : nums) {
            if (n == 2) {
                ans.push_back(-1);
                continue;
            }

            int p = 1;
            while (n & p) {
                p <<= 1;
            }

            ans.push_back(n - (p >> 1));
        }

        return ans;
    }
};
