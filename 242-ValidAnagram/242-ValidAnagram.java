// Last updated: 10/31/2026, 10:59:15 PM
1class Solution {
2    public boolean isAnagram(String s, String t) {
3        int[] arr = new int[26];
4        for(char c : s.toCharArray()) {
5            arr[c - 'a']++;
6        }
7        for(char c : t.toCharArray()) {
8            arr[c - 'a']--;
9        }
10        for(int i = 0; i < 26; i++) {
11            if(arr[i] != 0) return false;
12        }
13        return true;
14    }
15}