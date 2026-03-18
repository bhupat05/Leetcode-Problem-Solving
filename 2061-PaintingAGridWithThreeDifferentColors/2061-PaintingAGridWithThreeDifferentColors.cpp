// Last updated: 3/18/2026, 2:23:30 PM
class Solution {
public:
    vector<string> columns;
    int M = 1e9 + 7;
    unordered_map<string, int> memo;

    void generate(string curr, char pre, int l, int m) {
        if (l == m) {
            columns.push_back(curr);
            return;
        }

        for (char ch : {'R', 'G', 'B'}) {
            if (ch == pre) continue;
            generate(curr + ch, ch, l + 1, m);
        }
    }

    int solve(int remainc, int preIdx, int m) {
        if (remainc == 0) return 1;

        string key = to_string(remainc) + "_" + to_string(preIdx);
        if (memo.find(key) != memo.end()) return memo[key];

        int ways = 0;
        string pre = columns[preIdx];

        for (int i = 0; i < columns.size(); i++) {
            if (i == preIdx) continue;

            string curr = columns[i];
            bool valid = true;

            for (int j = 0; j < m; j++) {
                if (pre[j] == curr[j]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ways = (ways + solve(remainc - 1, i, m)) % M;
            }
        }

        return memo[key] = ways;
    }

    int colorTheGrid(int m, int n) {
        generate("", '#', 0, m);  // Generate all valid columns

        int result = 0;
        for (int i = 0; i < columns.size(); i++) {
            result = (result + solve(n - 1, i, m)) % M;
        }

        return result;
    }
};
