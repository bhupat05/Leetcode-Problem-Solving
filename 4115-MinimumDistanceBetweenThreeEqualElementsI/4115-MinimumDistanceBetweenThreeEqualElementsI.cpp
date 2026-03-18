// Last updated: 3/18/2026, 2:19:37 PM
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int curr = -1;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    if(nums[i] == nums[j] && nums[k] == nums[j]) {
                        curr = abs(i - j) + abs(j - k) + abs(i - k);
                        ans = min(ans, curr);
                    }
                }
            }
        }

        return min(ans, curr);
    }
};