// Last updated: 3/18/2026, 2:20:58 PM
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                result[i] = nums[i];
            } 
            else if(nums[i] > 0) {
                int x = nums[i] % n;
                result[i] = nums[(i + x) % n];   
            } 
            else {
                int x = abs(nums[i]) % n;
                result[i] = nums[(i - x + n) % n]; 
            }
        }
        return result;
    }
};
