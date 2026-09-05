// Last updated: 9/5/2026, 8:40:26 AM
1class Solution {
2public:
3    int firstStableIndex(vector<int>& nums, int k) {
4        int n = nums.size();
5        int mx = nums[0];
6        vector<int> suff(n, 0);
7        suff[n - 1] = nums[n - 1];
8        for(int i = n - 2; i >= 0; i--){
9            suff[i] = min(suff[i + 1], nums[i]);
10        }   
11
12        for(int i = 0; i < n; i++) {
13            mx = max(mx, nums[i]);
14            if((mx - suff[i]) <= k) return i;
15            
16        }
17        return -1;
18    }
19};