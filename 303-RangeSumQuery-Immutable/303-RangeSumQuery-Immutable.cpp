// Last updated: 9/16/2026, 2:33:38 AM
1class NumArray {
2public:
3    vector<int> nums;
4    NumArray(vector<int>& nums) : nums(nums) {
5        
6    }
7    
8    int sumRange(int left, int right) {
9        int sum = 0;
10        for(int i = left; i <= right; i++) {
11            sum += nums[i];
12        }
13        return sum;
14    }
15};
16
17/**
18 * Your NumArray object will be instantiated and called as such:
19 * NumArray* obj = new NumArray(nums);
20 * int param_1 = obj->sumRange(left,right);
21 */