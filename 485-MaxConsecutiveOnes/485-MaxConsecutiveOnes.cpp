// Last updated: 3/18/2026, 2:27:19 PM
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int m = 0;
        int curr = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                m = max(m,curr);
                curr = 0;
            }else{
                curr++;
            }
        }
          m = max(m,curr);
        return m;
    }
};