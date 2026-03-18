// Last updated: 3/18/2026, 3:01:45 PM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count =2;

        if(nums.size()<=2){
            return nums.size();
        }
        for(int i=2; i<nums.size(); i++){
            if(nums[i] != nums[count-2]){
                nums[count++] = nums[i];
            }
        }
        return count;
    }
};