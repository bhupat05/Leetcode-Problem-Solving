// Last updated: 3/18/2026, 2:23:37 PM
class Solution {
public:
    int minFlips(string s) {

        int n = s.size();
        string t = s + s;

        int ans = INT_MAX;
        int diff1 = 0, diff2 = 0;

        for(int i = 0; i < t.size(); i++) {

            char p1;
            char p2;

            if(i % 2 == 0){
                p1 = '0';
                p2 = '1';
            }
            else{
                p1 = '1';
                p2 = '0';
            }

            if(t[i] != p1) diff1++;
            if(t[i] != p2) diff2++;

            if(i >= n){
                int j = i - n;

                char old1, old2;

                if(j % 2 == 0){
                    old1 = '0';
                    old2 = '1';
                }
                else{
                    old1 = '1';
                    old2 = '0';
                }

                if(t[j] != old1) diff1--;
                if(t[j] != old2) diff2--;
            }

            if(i >= n - 1){
                ans = min(ans, min(diff1, diff2));
            }
        }

        return ans;
    }
};