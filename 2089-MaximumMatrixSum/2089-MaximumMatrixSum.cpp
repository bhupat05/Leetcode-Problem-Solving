// Last updated: 3/18/2026, 2:23:29 PM
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum = 0;
        int negCount = 0;
        int minAbs = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = matrix[i][j];
                sum += abs(val);

                if (val < 0) negCount++;
                minAbs = min(minAbs, abs(val));
            }
        }

        if (negCount % 2 == 0) {
            return sum;
        } else {
            return sum - 2LL * minAbs;
        }
    }
};
