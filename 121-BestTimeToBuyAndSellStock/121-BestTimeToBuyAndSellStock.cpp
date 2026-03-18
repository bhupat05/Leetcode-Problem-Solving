// Last updated: 3/18/2026, 2:30:25 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int mini = prices[0];
        int p = 0;
        for(int i=1; i<n; i++){
            p = max(p, prices[i]-mini);
            mini = min(mini,prices[i]);
        }
        return p;
    }
};