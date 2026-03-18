// Last updated: 3/18/2026, 2:25:49 PM
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();

        vector<int> sorted(m - 1, false);
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            bool need = false;

            for(int j = 0; j < m - 1; j++) {
                if(!sorted[j] && strs[j][i] > strs[j + 1][i]) {
                    need = true;
                    break;
                }
            }

            if(need) {
                cnt++;
            } else {
                for(int j = 0; j < m - 1; j++) {
                    if(!sorted[j] && strs[j][i] < strs[j + 1][i]) {
                        sorted[j] = true;
                    }
                }
            }
        }
        return cnt;
    }
};
