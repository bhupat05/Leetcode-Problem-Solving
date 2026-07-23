// Last updated: 7/23/2026, 9:32:22 AM
1class Solution {
2public:
3    vector<int> topKFrequent(vector<int>& nums, int k) {
4
5        unordered_map<int, int> freq;
6
7        for (int num : nums) {
8            freq[num]++;
9        }
10
11        vector<vector<int>> bucket(nums.size() + 1);
12
13        for (auto &p : freq) {
14            bucket[p.second].push_back(p.first);
15        }
16
17        vector<int> ans;
18
19        for (int i = nums.size(); i >= 1 && ans.size() < k; i--) {
20
21            for (int num : bucket[i]) {
22                ans.push_back(num);
23
24                if (ans.size() == k)
25                    return ans;
26            }
27        }
28
29        return ans;
30    }
31};