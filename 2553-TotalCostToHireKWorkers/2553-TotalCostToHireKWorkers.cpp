// Last updated: 3/18/2026, 2:22:29 PM
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {

        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>> leftPQ, rightPQ;

        long long ans = 0;
        int hired = 0;

        int i = 0;         
        int j = n - 1;     

        while (hired < k) {

            while (leftPQ.size() < candidates && i <= j) {
                leftPQ.push(costs[i]);
                i++;
            }

            while (rightPQ.size() < candidates && j >= i) {
                rightPQ.push(costs[j]);
                j--;
            }

            int leftMin  = leftPQ.empty() ? INT_MAX : leftPQ.top();
            int rightMin = rightPQ.empty() ? INT_MAX : rightPQ.top();

            if (leftMin <= rightMin) {
                ans += leftMin;
                leftPQ.pop();
            } else {
                ans += rightMin;
                rightPQ.pop();
            }

            hired++;
        }

        return ans;
    }
};
