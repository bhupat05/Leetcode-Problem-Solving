// Last updated: 3/18/2026, 2:20:15 PM
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();

        map<int,long long> l, r;   

        for (int x : nums) r[x]++; 

        long long ans = 0;

        for (int j = 0; j < n; j++) {
            int x = nums[j];

            r[x]--;  

            long long target = 2LL * x;

            if (r.count(target) && l.count(target)) {
                ans = (ans + l[target] * r[target]) % MOD;
            }

            l[x]++;  
        }

        return ans;
    }
};
