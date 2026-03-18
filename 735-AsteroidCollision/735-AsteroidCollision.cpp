// Last updated: 3/18/2026, 2:26:37 PM
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int a : asteroids) {
            if(a > 0) {
                st.push(a);
            } 
            else { 
                while(!st.empty() && st.top() > 0 && st.top() < abs(a)) {
                    st.pop();  
                }

                if(st.empty() || st.top() < 0) {
                    st.push(a);
                }
                else if(st.top() == abs(a)) {
                    st.pop();
                }
            }
        }

        vector<int> r;
        while(!st.empty()) {
            r.push_back(st.top());
            st.pop();
        }
        reverse(r.begin(), r.end());
        return r;
    }
};
