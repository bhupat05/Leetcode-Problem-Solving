// Last updated: 6/28/2026, 7:39:47 AM
1class Solution {
2    public String predictPartyVictory(String senate) {
3
4        int n = senate.length();
5
6        Queue<Integer> radiant = new LinkedList<>();
7        Queue<Integer> dire = new LinkedList<>();
8
9        for (int i = 0; i < n; i++) {
10            if (senate.charAt(i) == 'R')
11                radiant.add(i);
12            else
13                dire.add(i);
14        }
15
16        while (!radiant.isEmpty() && !dire.isEmpty()) {
17
18            int r = radiant.poll();
19            int d = dire.poll();
20
21            if (r < d) {
22                radiant.add(r + n);
23            } else {
24                dire.add(d + n);
25            }
26        }
27
28        return radiant.isEmpty() ? "Dire" : "Radiant";
29    }
30}