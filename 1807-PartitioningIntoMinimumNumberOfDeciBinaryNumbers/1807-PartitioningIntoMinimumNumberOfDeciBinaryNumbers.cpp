// Last updated: 3/18/2026, 2:23:55 PM
class Solution {
public:
    int minPartitions(string n) {
        int r = 0;

        for(char c : n) {
            int x = c - '0';
            if(x > r) r = x;
        }
        return r;
    }
};