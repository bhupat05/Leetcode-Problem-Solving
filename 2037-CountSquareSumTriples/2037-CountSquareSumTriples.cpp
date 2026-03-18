// Last updated: 3/18/2026, 2:23:34 PM
class Solution {
public:
    int countTriples(int n) {
        unordered_set<int> st;

        for(int i = 1; i <= n; i++) {
            st.insert(i * i);
        }

        int count = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(st.count(i * i + j * j)) {
                    count++;
                }
            }
        }
        return count;
    }
};