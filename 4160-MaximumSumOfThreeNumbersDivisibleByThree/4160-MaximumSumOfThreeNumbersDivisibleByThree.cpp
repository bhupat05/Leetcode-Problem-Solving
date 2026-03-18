// Last updated: 3/18/2026, 2:19:16 PM
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        priority_queue<int> pq0, pq1, pq2;

        for (int x : nums) {
            if (x % 3 == 0) pq0.push(x);
            else if (x % 3 == 1) pq1.push(x);
            else pq2.push(x);
        }

        int ans = 0;

        if (pq0.size() >= 3) {
            int a = pq0.top(); pq0.pop();
            int b = pq0.top(); pq0.pop();
            int c = pq0.top(); pq0.pop();
            ans = max(ans, a + b + c);
            pq0.push(a); pq0.push(b); pq0.push(c); 
        }

        if (pq1.size() >= 3) {
            int a = pq1.top(); pq1.pop();
            int b = pq1.top(); pq1.pop();
            int c = pq1.top(); pq1.pop();
            ans = max(ans, a + b + c);
            pq1.push(a); pq1.push(b); pq1.push(c);
        }

        if (pq2.size() >= 3) {
            int a = pq2.top(); pq2.pop();
            int b = pq2.top(); pq2.pop();
            int c = pq2.top(); pq2.pop();
            ans = max(ans, a + b + c);
            pq2.push(a); pq2.push(b); pq2.push(c);
        }

        if (!pq0.empty() && !pq1.empty() && !pq2.empty()) {
            ans = max(ans, pq0.top() + pq1.top() + pq2.top());
        }

        return ans;
    }
};
