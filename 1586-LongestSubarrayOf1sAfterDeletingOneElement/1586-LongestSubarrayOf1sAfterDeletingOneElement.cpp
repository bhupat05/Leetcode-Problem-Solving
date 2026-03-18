// Last updated: 3/18/2026, 2:24:18 PM
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int c = 0;
        int f = 0;
        int l = 0;

        for(int i=0; i<n; i++){
            c += (nums[i] == 0);

            while(c > 1){
                c -= (nums[l] == 0);
                l++;
            }
            f = max(f,i-l);
        }
        return f;
       
    }
};