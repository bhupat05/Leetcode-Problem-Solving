// Last updated: 3/18/2026, 3:01:59 PM
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string curr = "";

        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {
                if (curr == "" || curr == ".") {
                } 
                else if (curr == "..") {
                    if (!st.empty()) st.pop();
                } 
                else {
                    st.push(curr);
                }
                curr = "";   
            } 
            else {
                curr += path[i];
            }
        }

        string result = "";
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        return result.empty() ? "/" : result;
    }
};
