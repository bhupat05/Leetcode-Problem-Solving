// Last updated: 3/18/2026, 3:02:51 PM
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
         int c=0;
        for(int i=0; i<nums.size(); i++){
           if(nums[i] != val){
            swap(nums[i],nums[c]);
            c++;
            }
        }
        return c;
    }
};