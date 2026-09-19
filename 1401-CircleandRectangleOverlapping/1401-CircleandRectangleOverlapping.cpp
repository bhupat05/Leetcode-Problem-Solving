// Last updated: 9/20/2026, 12:21:16 AM
1class Solution {
2public:
3    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
4
5        if(xCenter < x1 && abs(xCenter - x1) > radius) return false;
6        if(xCenter > x2 && abs(xCenter - x2) > radius) return false;
7        if(yCenter < y1 && abs(yCenter - y1) > radius) return false;
8        if(yCenter > y2 && abs(yCenter - y2) > radius) return false;
9
10        if((xCenter < x1 || xCenter > x2) && (yCenter < y1 || yCenter > y2)) {
11
12            int x = (xCenter < x1) ? x1 : x2;
13            int y = (yCenter < y1) ? y1 : y2;
14
15            if((xCenter-x) * (xCenter-x) + (yCenter-y) * (yCenter-y) > radius * radius) {
16                return false;
17            }
18        }
19
20        return true;
21    }
22};