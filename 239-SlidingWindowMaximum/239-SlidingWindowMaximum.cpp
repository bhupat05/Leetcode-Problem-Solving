// Last updated: 8/15/2026, 7:05:37 PM
1class Solution {
2public:
3    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
4        int n = nums.size();
5
6        deque<int> deq;
7        vector<int> result;
8
9        for(int i = 0; i < n; i++){
10            if(i >= k && deq.front() == nums[i - k]) deq.pop_front();
11
12            while(!deq.empty() && nums[i] > deq.back()){
13                deq.pop_back();
14            }
15            deq.push_back(nums[i]);
16
17            if(i >= k - 1){
18                result.push_back(deq.front());
19            }
20        }
21        return result;
22    }
23};