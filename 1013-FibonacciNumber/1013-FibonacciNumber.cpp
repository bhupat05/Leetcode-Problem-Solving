// Last updated: 3/18/2026, 2:25:45 PM
class Solution {
    void multiply(vector<vector<long long>> &A, vector<vector<long long>> &B) {
        vector<vector<long long>> res(2, vector<long long>(2, 0));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    res[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        A = res;
    }

    void power(vector<vector<long long>> &M, int n) {
        if (n <= 1) return;
        power(M, n / 2);
        multiply(M, M);
        if (n % 2 != 0) {
            vector<vector<long long>> F = {{1,1},{1,0}};
            multiply(M, F);
        }
    }

public:
    int fib(int n) {
        if (n == 0) return 0;
        vector<vector<long long>> M = {{1,1},{1,0}};
        power(M, n-1);
        return M[0][0];
    }
};
