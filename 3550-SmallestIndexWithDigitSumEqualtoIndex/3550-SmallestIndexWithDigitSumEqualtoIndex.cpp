// Last updated: 9/24/2026, 7:37:26 PM
1class Solution {
2public:
3    int smallestIndex(vector<int>& nums) {
4        int n = nums.size();
5        
6        for(int i=0; i<n; i++){
7            int sum = 0;
8            while(nums[i]>0){
9                sum += nums[i]%10;
10                nums[i] = nums[i]/10;
11            }
12            if(i == sum) return i;
13        }
14        return -1;
15    }
16};