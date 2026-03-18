// Last updated: 3/18/2026, 2:27:34 PM
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {

        unordered_set<string> st(bank.begin(), bank.end());
        if (st.find(endGene) == st.end()) return -1;

        queue<pair<string, int>> q;
        q.push({startGene, 0});

        vector<char> genes = {'A', 'C', 'G', 'T'};

        while (!q.empty()) {
            auto [curr, steps] = q.front();
            q.pop();

            if (curr == endGene) return steps;

            for (int i = 0; i < 8; i++) {
                char original = curr[i];

                for (char g : genes) {
                    curr[i] = g;

                    if (st.count(curr)) {
                        st.erase(curr);         
                        q.push({curr, steps + 1});
                    }
                }

                curr[i] = original;
            }
        }

        return -1; 
    }
};
