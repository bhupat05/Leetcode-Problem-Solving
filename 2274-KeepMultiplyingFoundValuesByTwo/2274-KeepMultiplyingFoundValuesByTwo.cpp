// Last updated: 3/18/2026, 2:22:56 PM
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> st(nums.begin(), nums.end());

        while(st.count(original)) {
            original *= 2;
        }
        return original;
    }
};