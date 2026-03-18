// Last updated: 3/18/2026, 2:28:57 PM
class Solution {
public:
    void solve(int k, int n, vector<int> &curr, int start,
               vector<vector<int>> &result) {

        if (curr.size() == k) {
            if (n == 0) 
                result.push_back(curr);
            return;
        }

        for (int num = start; num <= 9; num++) {

            if (num > n) break;

            curr.push_back(num);
            solve(k, n - num, curr, num + 1, result);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> curr;

        solve(k, n, curr, 1, result);
        return result;
    }
};
