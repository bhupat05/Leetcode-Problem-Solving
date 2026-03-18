// Last updated: 3/18/2026, 3:01:53 PM
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int a = 0;
        int b = 0;
        int c = 0;

        for(int i = 0; i <n; i++){
            if(nums[i] == 0){
                a++;
            }else if(nums[i] == 1){
                b++;
            }else{
                c++;
            }
        }

        for(int i = 0; i < a; i++){
            nums[i] = 0;
        }
        for(int i = a; i < b + a; i++){
            nums[i] = 1;
        }
        for(int i = a + b; i < n; i++){
            nums[i] = 2;
        }

         
    }
};