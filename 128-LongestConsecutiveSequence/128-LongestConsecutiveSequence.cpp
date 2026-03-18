// Last updated: 3/18/2026, 2:30:16 PM
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;

        for (int x : st) {
            if (!st.count(x - 1)) {
                int y = x;
                while (st.count(y)) y++;
                longest = max(longest, y - x);
            }
        }

        return longest;
    }
};