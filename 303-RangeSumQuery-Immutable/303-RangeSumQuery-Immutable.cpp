// Last updated: 9/16/2026, 2:36:01 AM
1class NumArray {
2public:
3    vector<int> pre;
4    NumArray(vector<int>& nums) {
5        int n = nums.size();
6        pre.resize(n + 1, 0);
7
8        for(int i = 0; i < n; i++) {
9            pre[i + 1] = pre[i] + nums[i];
10        }
11    }
12    
13    int sumRange(int left, int right) {
14        return pre[right + 1] - pre[left];
15    }
16};
17
18/**
19 * Your NumArray object will be instantiated and called as such:
20 * NumArray* obj = new NumArray(nums);
21 * int param_1 = obj->sumRange(left,right);
22 */