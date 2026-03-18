// Last updated: 3/18/2026, 2:26:56 PM
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        double sum = 0;
        double result = 0;

        for(int i = 0; i < k; i++) {
            sum += nums[i];
        }
        result = sum / k;
        int l = 0;

        for(int i = k; i < n; i++) {
            sum += nums[i] - nums[l];
            result = max(result, sum / k);
            l++;
        }
        return result;
        
    }
};