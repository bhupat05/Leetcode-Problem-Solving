// Last updated: 4/13/2026, 10:55:34 AM
1class Solution {
2public:
3    int findMin(vector<int>& nums) {
4        int l = 0;
5        int r = nums.size() - 1;
6
7        while(l < r) {
8            int mid = l + (r - l) / 2;
9
10            if(nums[l] == nums[mid] && nums[mid] == nums[r]) {
11                l++;
12                r--;
13            }
14            else if(nums[mid] > nums[r]) {
15                l = mid + 1;
16            } 
17            else {
18                r = mid;
19            }
20        }
21        return nums[l];  
22    }
23};