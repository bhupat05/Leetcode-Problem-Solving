// Last updated: 11/5/2026, 11:33:36 PM
1class Solution {
2    public int longestConsecutive(int[] nums) {
3        HashSet<Integer> st = new HashSet<>();
4        int ans = 0;
5        for(int num : nums) {
6            st.add(num);
7        }
8
9        for(int num : st) {
10            if(st.contains(num) && !st.contains(num - 1)) {
11                int x = num;
12                int curr = 0;
13                while(st.contains(x)) {
14                    x++;
15                    curr++;
16                }
17                ans = Math.max(ans, curr);
18            }
19        }
20        return ans;
21    }
22}