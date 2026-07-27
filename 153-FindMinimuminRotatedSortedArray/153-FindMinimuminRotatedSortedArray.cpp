// Last updated: 7/27/2026, 10:29:18 PM
1class Solution {
2public:
3    int findMin(vector<int>& nums) {
4        int n = nums.size();
5        int l = 0;
6        int r = n - 1;
7        
8        while (l < r) {
9            int mid = l + (r - l) / 2;  
10            
11            if (nums[mid] > nums[r]) {
12                l = mid + 1;  
13            } else {
14                r = mid;  
15            }
16        }
17        return nums[l];
18    }
19};
20