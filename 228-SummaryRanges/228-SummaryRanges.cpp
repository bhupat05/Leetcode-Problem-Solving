// Last updated: 3/18/2026, 2:28:46 PM
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> r;
        int n = nums.size();
        if (n == 0) return r;

        int l = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1] + 1) {

                if (nums[l] == nums[i - 1]) {
                    r.push_back(to_string(nums[l]));
                } else {
                    r.push_back(to_string(nums[l]) + "->" + to_string(nums[i - 1]));
                }

                l = i;
            }
        }

        if (nums[l] == nums[n - 1]) {
            r.push_back(to_string(nums[l]));
        } else {
            r.push_back(to_string(nums[l]) + "->" + to_string(nums[n - 1]));
        }

        return r;
    }
};
