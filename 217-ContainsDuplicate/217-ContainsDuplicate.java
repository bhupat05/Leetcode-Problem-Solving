// Last updated: 10/29/2026, 10:39:26 PM
1class Solution {
2    public boolean containsDuplicate(int[] nums) {
3        Set<Integer> st = new HashSet<>();
4
5        for(int x : nums) {
6            if(st.contains(x)) return true;
7            st.add(x);
8        }
9        return false;
10    }
11}