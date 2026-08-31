// Last updated: 8/31/2026, 6:22:33 PM
1class Solution {
2public:
3    vector<string> largestString(vector<int>& nums) {
4        int n = nums.size();
5        vector<string> ans;
6
7        for(int x : nums) {
8            string t = "";
9            int cnt = 0;
10            while(x > 0 && cnt < 25) {
11                int r = x % 2;
12                x = x / 2;
13                if(r == 1) {
14                    char c = cnt + 'a';
15                    t = c + t;
16                }
17
18
19                cnt++;
20            }
21            t = string(x, 'z') + t;
22            ans.push_back(t);
23        }
24        return ans;
25    }
26};