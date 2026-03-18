// Last updated: 3/18/2026, 2:19:07 PM
class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        for(int i = 0; i < n - 1; i++) {
            int sum = 0;
            for(int j = i + 1; j < n; j++) {
                sum += nums[j];
            }
            sum /= n - i - 1;
            if(nums[i] > sum) cnt++;
        }
        return cnt;
    }
};