// Last updated: 6/10/2026, 9:02:22 AM
1class Solution {
2public:
3    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
4
5        int size = flowerbed.size();
6        int k = 0;  
7
8        if (size == 1) {
9            if (flowerbed[0] == 0) k = 1;
10            return k >= n;
11        }
12
13        if (flowerbed[0] == 0 && flowerbed[1] == 0) {
14            k++;
15            flowerbed[0] = 1; 
16        }
17
18        for (int i = 1; i < size - 1; i++) {
19            if (flowerbed[i] == 0 &&
20                flowerbed[i - 1] == 0 &&
21                flowerbed[i + 1] == 0) 
22            {
23                k++;
24                flowerbed[i] = 1; 
25            }
26        }
27
28        
29        if (flowerbed[size - 1] == 0 && flowerbed[size - 2] == 0) {
30            k++;
31            
32        }
33
34        return k >= n;
35    }
36};
37