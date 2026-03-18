// Last updated: 3/18/2026, 2:21:52 PM
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int hMax = 1;
        int vMax = 1;

        int curr = 1;

        for(int i = 1; i < hBars.size(); i++) {
            if(hBars[i] == hBars[i - 1] + 1) {
                curr++;
            } else {
                curr = 1;
            }
            hMax = max(hMax, curr);
        }

        curr = 1;

        for(int i = 1; i < vBars.size(); i++) {
            if(vBars[i] == vBars[i - 1] + 1) {
                curr++;
            } else {
                curr = 1;
            }
            vMax = max(vMax, curr);
        }

        int r = min(vMax + 1, hMax + 1);

        return r * r;
    }
};