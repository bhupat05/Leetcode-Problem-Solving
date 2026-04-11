// Last updated: 4/11/2026, 8:03:47 PM
1class Solution {
2public:
3    string trafficSignal(int timer) {
4        if(timer == 0) {
5            return "Green";
6        } else if(timer == 30) {
7            return "Orange";
8        } else if(timer > 30 && timer <= 90) {
9            return "Red";
10        }
11        return "Invalid";
12    }
13};