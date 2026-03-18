// Last updated: 3/18/2026, 2:20:50 PM
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int result = 0;
        int n = nums.size();

        for(int i=0; i<n-1; i++){
            result = max(result,abs(nums[i]-nums[i+1]));
        }
        return max(result,abs(nums[0]-nums[n-1]));
    }
    
};