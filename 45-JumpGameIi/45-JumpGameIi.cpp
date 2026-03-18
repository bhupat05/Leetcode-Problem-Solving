// Last updated: 3/18/2026, 3:02:31 PM
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int currentEnd = 0;
        int longest = 0;

        for (int i = 0; i < n - 1; i++) {
            longest = max(longest, i + nums[i]);
            if (i == currentEnd) {  
                jumps++;
                currentEnd = longest;
            }
        }

        return jumps;
    }
};
