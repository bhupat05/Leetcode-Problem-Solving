// Last updated: 3/18/2026, 2:25:13 PM
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> answer(n, 0);
        stack<int> st;  
        
        for (int i = n - 1; i >= 0; i--) {
            int count = 0;
            
            while (!st.empty() && heights[i] > st.top()) {
                st.pop();
                count++;
            }
            
            if (!st.empty()) {
                count++;
            }
            
            answer[i] = count;
            st.push(heights[i]);
        }
        
        return answer;
    }
};