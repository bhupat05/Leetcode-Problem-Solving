// Last updated: 3/18/2026, 2:25:42 PM
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {


        int n = nums.size();

        vector<int>res(n,0);
        
        
        int l = 0;
        int r = n-1;

        int k = n-1;

        while(k>=0){
            int a = nums[l]*nums[l];
            int b = nums[r]*nums[r];

            if(a>b){
                res[k] = a;
                l++;
            }else{
                res[k] = b;
                r--;
            }
            k--;
        }
        return res;
    }
};