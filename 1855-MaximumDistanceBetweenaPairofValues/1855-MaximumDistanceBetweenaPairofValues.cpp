// Last updated: 4/19/2026, 11:01:40 AM
1class Solution {
2public:
3    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
4        int n = nums1.size();
5        int maxi = 0;
6
7        for(int i = 0; i < n; i++) {
8            int l = i;
9            int r = nums2.size() - 1;
10
11            int ans = i;
12            while(l <= r) {
13                int mid = l + (r - l) / 2;
14                if(nums2[mid] >= nums1[i]) {
15                    ans = mid;
16                    l = mid + 1;
17                } else {
18                    r = mid - 1;
19                }
20            }
21            maxi = max(maxi, ans - i);
22        }
23        return maxi;
24    }
25};