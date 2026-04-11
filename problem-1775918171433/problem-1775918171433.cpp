// Last updated: 4/11/2026, 8:06:11 PM
1class Solution {
2public:
3    int countDigitOccurrences(vector<int>& nums, int digit) {
4        int n = nums.size();
5
6        int cnt = 0;
7
8        for(int &x : nums) {
9            while(x > 0) {
10                int d = x % 10;
11                if(d == digit) cnt++;
12                x /= 10;
13            }
14        }
15        return cnt;
16    }
17};