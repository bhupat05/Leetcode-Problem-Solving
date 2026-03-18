// Last updated: 3/18/2026, 3:02:53 PM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k = 1;

        for(int i = 1; i < n; i++) {
            if(nums[i] != nums[i - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k; 
    }
};