// Last updated: 3/18/2026, 2:23:07 PM
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        long long curr = 1;   

        ans += curr;         

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] == prices[i - 1] - 1) {
                curr = curr + 1;   
            } else {
                curr = 1;          
            }
            ans += curr;
        }

        return ans;
    }
};
