// Last updated: 6/10/2026, 9:05:08 AM
1class Solution {
2public:
3    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
4        int m = flowerbed.size();
5        if(m == 1) {
6            if(n == 1) {
7                if(flowerbed[0] == 0) return true;
8            } else if(n == 0) return true;
9            else {
10                return false;
11            }
12        }
13
14        if(flowerbed[0] == 0 && flowerbed[1] == 0) {
15            n--;
16            flowerbed[0] = 1;
17        }
18        if(flowerbed[m - 1] == 0 && flowerbed[m - 2] == 0) {
19            n--;
20            flowerbed[m - 1] = 1;
21        }
22
23        for(int i = 1; i < m - 1; i++) {
24            if(flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
25                flowerbed[i] = 1;
26                n--;
27            } 
28        }
29        cout << n << "\n";
30        return n <= 0;
31    }
32};