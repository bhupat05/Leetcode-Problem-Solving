// Last updated: 9/14/2026, 1:15:45 AM
1class Solution {
2public:
3    vector<int> findDisappearedNumbers(vector<int>& nums) {
4        int n = nums.size();
5
6        int i = 0;
7        while(i < n) {
8            int j = nums[i] - 1;
9            if(j >= 0 && j < n && nums[i] != nums[j]) {
10                swap(nums[i], nums[j]);
11            } else {
12                i++;
13            }
14        }
15        vector<int> r;
16        for(int i = 0; i < n; i++) {
17            if(nums[i] != i + 1) {
18                r.push_back(i + 1);
19            }
20        }
21        return r;
22    }
23};