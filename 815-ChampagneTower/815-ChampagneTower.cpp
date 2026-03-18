// Last updated: 3/18/2026, 2:26:14 PM
class Solution {
public:
    double champagneTower(int poured, int m, int n) {
        double dp[101][101] = {0};   // Initialize to 0
        
        dp[0][0] = poured;

        for(int i = 0; i < 100; i++) {
            for(int j = 0; j <= i; j++) {
                if(dp[i][j] > 1) {
                    dp[i + 1][j] += (dp[i][j] - 1) / 2.0;      
                    dp[i + 1][j + 1] += (dp[i][j] - 1) / 2.0;   
                    dp[i][j] = 1;
                }
            }
        }

        return min(1.0, dp[m][n]);
    }
};
