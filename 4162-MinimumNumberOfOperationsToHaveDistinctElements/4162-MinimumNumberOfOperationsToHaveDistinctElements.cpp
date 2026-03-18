// Last updated: 3/18/2026, 2:19:15 PM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st(nums.begin(), nums.end());
        unordered_map<int, int> mp;

        for (int x : nums) {
            mp[x]++;
        }

        if (st.size() == nums.size()) return 0;

        int cnt = 0;

        for (int i = 0; i < n; i += 3) {
            cnt++;

            for (int k = 0; k < 3 && i + k < n; k++) {
                int val = nums[i + k];

                mp[val]--;

                if (mp[val] == 0) {
                    st.erase(val);
                }
            }

            int remaining = n - (i + 3);

            if (remaining <= 0 || st.size() == remaining) {
                return cnt;
            }
        }

        return cnt;
    }
};
