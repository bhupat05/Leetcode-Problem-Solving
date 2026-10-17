// Last updated: 10/17/2026, 9:19:28 PM
1class Solution {
2    public int calPoints(String[] operations) {
3        int ans = 0;
4        ArrayList<Integer> arr = new ArrayList<>();
5        for(String  c : operations) {
6            if(c.equals("D")) {
7                arr.add(2 * arr.get(arr.size() - 1));
8            } else if(c.equals("C")) {
9                arr.remove(arr.size() - 1);
10            } else if(c.equals("+")) {
11                arr.add(arr.get(arr.size() - 1) + arr.get(arr.size() - 2));
12            } else {
13                arr.add(Integer.parseInt(c));    
14            }
15        }
16        for(int i = 0; i < arr.size(); i++) {
17            ans += arr.get(i);
18        }
19        return ans;
20    }
21}