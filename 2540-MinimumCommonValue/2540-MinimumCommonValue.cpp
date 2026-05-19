// Last updated: 5/19/2026, 8:00:43 AM
1class Solution {
2public:
3    int getCommon(vector<int>& nums1, vector<int>& nums2) {
4        int l1 = 0, l2 = 0;
5        int n1 = nums1.size();
6        int n2 = nums2.size();
7
8        while (l1 < n1 && l2 < n2) {
9            if (nums1[l1] == nums2[l2]) {
10                return nums1[l1];
11            }
12            else if (nums1[l1] < nums2[l2]) {
13                l1++;
14            }
15            else {
16                l2++;
17            }
18        }
19
20        return -1;
21    }
22};