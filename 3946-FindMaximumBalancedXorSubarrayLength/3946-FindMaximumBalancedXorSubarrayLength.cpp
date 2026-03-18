// Last updated: 3/18/2026, 2:20:04 PM
class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixXor(n);
        vector<int> prefixDiff(n);

        prefixXor[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixXor[i] = prefixXor[i - 1] ^ nums[i];
        }
           

        
        prefixDiff[0] = (nums[0] % 2 == 0 ? 1 : -1);
        for (int i = 1; i < n; i++) {
            prefixDiff[i] = prefixDiff[i - 1] + (nums[i] % 2 == 0 ? 1 : -1);
        }

        unordered_map<long long, int> mp;

        
        long long initKey = ((long long)0 << 32) ^ (unsigned)0;
        mp[initKey] = -1;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long px = prefixXor[i];
            long long pd = prefixDiff[i];

            long long key = (px << 32) ^ (unsigned)pd;

            if (mp.count(key)) {
                ans = max(ans, i - mp[key]);
            } else {
                mp[key] = i;
            }
        }

        return ans;
    }
};
