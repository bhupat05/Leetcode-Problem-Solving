// Last updated: 3/18/2026, 2:19:55 PM
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        
        int l = 0;
        int odd = 0;
        int even = 0;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            unordered_set<int> st1;
            unordered_set<int> st2;
            for(int j = i; j < n; j++) {
                if(nums[j] % 2 == 0) {
                    st1.insert(nums[j]);
                } else {
                    st2.insert(nums[j]);
                }

                if(st1.size() == st2.size()) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};