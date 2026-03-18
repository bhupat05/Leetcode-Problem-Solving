// Last updated: 3/18/2026, 2:25:35 PM
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int maxi = -1;
        int curr = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                curr++;
                maxi = max(curr, maxi);
            } else {
                if(k > 0) {
                    curr++;
                    k--;
                    maxi = max(maxi, curr);
                } else {
                    while(l <= i && k <= 0) {
                        if(nums[l] == 0) {
                            k++;
                            l++;
                            curr--;
                        } else {
                            l++;
                            curr--;
                        }
                    }
                    curr++;
                    k--;
                    maxi = max(maxi, curr);

                }
               
                
                
            }
            
            
        }
        return maxi;
    }
};