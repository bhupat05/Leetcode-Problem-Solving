// Last updated: 3/18/2026, 2:25:04 PM
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        string r = "";

        stack<pair<char, int>> st;

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.push({'(', r.size()});
                r += s[i];
            } else if(s[i] == ')') {
                if(!st.empty() && st.top().first == '(') {
                    r += s[i];
                    st.pop();
                } 
            } else {
                r += s[i];
            }
        }

        while(!st.empty()) {
            char c = st.top().first;
            int idx = st.top().second;
            st.pop();
            r.erase(idx, 1);
        }
        return r;
    }
};