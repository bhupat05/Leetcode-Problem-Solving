// Last updated: 3/18/2026, 2:20:33 PM
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int count = 0;

        for (int num : nums) {
            while (!st.empty() && num < st.top()) {
                st.pop();
            }

            if (st.empty() || num > st.top()) {
                if (num > 0) count++;
                st.push(num);
            }
        }

        return count;
    }
};
