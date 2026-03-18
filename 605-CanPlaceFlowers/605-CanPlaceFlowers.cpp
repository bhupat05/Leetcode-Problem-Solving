// Last updated: 3/18/2026, 2:27:01 PM
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int size = flowerbed.size();
        int k = 0;  

        if (size == 1) {
            if (flowerbed[0] == 0) k = 1;
            return k >= n;
        }

        if (flowerbed[0] == 0 && flowerbed[1] == 0) {
            k++;
            flowerbed[0] = 1; 
        }

        for (int i = 1; i < size - 1; i++) {
            if (flowerbed[i] == 0 &&
                flowerbed[i - 1] == 0 &&
                flowerbed[i + 1] == 0) 
            {
                k++;
                flowerbed[i] = 1; 
            }
        }

        
        if (flowerbed[size - 1] == 0 && flowerbed[size - 2] == 0) {
            k++;
            
        }

        return k >= n;
    }
};
