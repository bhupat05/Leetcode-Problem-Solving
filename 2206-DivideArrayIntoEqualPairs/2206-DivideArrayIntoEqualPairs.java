// Last updated: 10/18/2026, 9:45:27 PM
1class Solution {
2    public boolean divideArray(int[] nums) {
3        int[] arr = new int[501];
4
5        for(int x : nums) {
6            arr[x]++;
7        }
8
9        for(int x : arr){
10            if(x % 2 != 0) return false;
11        }
12        return true;
13    }
14}