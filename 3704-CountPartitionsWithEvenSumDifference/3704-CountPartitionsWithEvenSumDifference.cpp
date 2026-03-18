// Last updated: 3/18/2026, 2:20:53 PM
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int leftSum = 0;
        int count = 0;

        for(int i = 0; i < nums.size() - 1; i++) {
            leftSum += nums[i];

            int rightSum = sum - leftSum;

            if((leftSum % 2) == (rightSum % 2)) {
                count++;
            }
        }
        return count;
    }
};