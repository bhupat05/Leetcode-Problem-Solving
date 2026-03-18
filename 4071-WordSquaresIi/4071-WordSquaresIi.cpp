// Last updated: 3/18/2026, 2:19:47 PM
class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words.size();
        vector<vector<string>> result;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(j == i) {
                    continue;
                }
                for(int k = 0; k < n; k++) {
                    if(k == i || k == j) {
                        continue;
                    }
                    for(int l = 0; l < n; l++) {
                        if(l == i || l == j || l == k) {
                            continue;
                        }

                            string t = words[i];
                            string le = words[j];
                            string r = words[k];
                            string b = words[l];

                            if(t[0] == le[0] && t[3] == r[0] && b[0] == le[3] && b[3] == r[3]) {
                                result.push_back({t, le, r, b});
                            }
                    }
                }
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};