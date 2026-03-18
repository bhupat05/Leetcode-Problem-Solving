// Last updated: 3/18/2026, 2:22:14 PM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int count1 = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) count1++;
        }   
        if(count1 > 0) {
            return n - count1;
        }

        int minstepTo1 = INT_MAX;

        for(int i = 0; i < n; i++) {
            int GCD = nums[i];
            for(int j = i + 1; j < n; j++) {
                GCD = gcd(GCD, nums[j]);

                if(GCD == 1) {
                    minstepTo1 = min(minstepTo1, j - i);
                    break;
                }
            }
        }
        return minstepTo1 == INT_MAX ? -1 : minstepTo1 + (n - 1);
    }
};