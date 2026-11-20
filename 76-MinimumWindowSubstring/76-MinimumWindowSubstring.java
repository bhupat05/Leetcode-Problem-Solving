// Last updated: 11/20/2026, 3:18:51 PM
1class Solution {
2    public String minWindow(String s, String t) {
3        int m = s.length();
4        int n = t.length();
5        int[] arr1 = new int[256];
6        int[] arr2 = new int[256];
7        int req = n;
8        for(char c : t.toCharArray()) {
9            arr1[c]++;
10        }
11        int left = 0;
12        int result = Integer.MAX_VALUE; 
13        int start = 0;
14
15        for(int i = 0; i < m; i++) {
16            if(arr2[s.charAt(i)] < arr1[s.charAt(i)]) {
17                req--;
18            }
19            arr2[s.charAt(i)]++;
20
21            while(req <= 0) {
22                if(result > (i - left + 1)) {
23                    result = i - left + 1;
24                    start = left;
25                }
26                if(arr1[s.charAt(left)] > 0 && arr2[s.charAt(left)] <= arr1[s.charAt(left)]) {
27                    req++;
28                }
29                arr2[s.charAt(left)]--;
30                left++;
31            }
32        }
33        return result == Integer.MAX_VALUE ? "" : s.substring(start, start + result);
34
35    }
36}