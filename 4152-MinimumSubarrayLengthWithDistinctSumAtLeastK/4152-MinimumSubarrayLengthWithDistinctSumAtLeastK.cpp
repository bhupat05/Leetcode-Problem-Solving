// Last updated: 3/18/2026, 2:19:21 PM
class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        int l = 0;
        int sum = 0;
        int cnt = 0;
        int ans = INT_MAX;

        for(int i = 0; i < n; i++) {
            if(mp[nums[i]] == 0) {
                sum += nums[i];
            }
            mp[nums[i]]++;

            while(sum >= k) {
                ans = min(ans, i - l + 1);

                mp[nums[l]]--;
                if(mp[nums[l]] == 0) {
                    sum -= nums[l];
                }
                l++;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};