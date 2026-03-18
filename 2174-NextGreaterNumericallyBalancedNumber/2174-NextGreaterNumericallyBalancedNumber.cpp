// Last updated: 3/18/2026, 2:23:15 PM
class Solution {
public:
    bool isValid(int x) {
        vector<int> freq(10, 0);

        while (x > 0) {
            int d = x % 10;
            if (d == 0) return false; 
            freq[d]++;
            x /= 10;
        }

        for (int d = 1; d <= 9; d++) {
            if (freq[d] > 0 && freq[d] != d) {
                return false;
            }
        }

        return true;
    }

    int nextBeautifulNumber(int n) {
        int x = n + 1;
        while (true) {
            if (isValid(x)) return x;
            x++;
        }
    }
};