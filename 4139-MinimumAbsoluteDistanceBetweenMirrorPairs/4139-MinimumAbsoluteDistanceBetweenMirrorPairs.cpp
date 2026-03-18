// Last updated: 3/18/2026, 2:19:28 PM
class Solution {
public:
    int rev(int x) {
        int r = 0;
        while (x > 0) {
            r = r * 10 + x % 10;
            x /= 10;
        }
        return r;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;  
        int ans = INT_MAX;
        int n = nums.size();

        for (int i = n - 1; i >= 0; i--) {
            int r = rev(nums[i]);

            if (mp.count(r)) {
                ans = min(ans, mp[r] - i);
            }

            mp[nums[i]] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
