// Last updated: 3/18/2026, 2:29:24 PM
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> profits;
        stack<pair<int, int>> st;   

        int i = 0;

        while (i < n) {
            while (i + 1 < n && prices[i] >= prices[i + 1])
                i++;
            int buy = i;

            while (i + 1 < n && prices[i] <= prices[i + 1])
                i++;
            int sell = i;

            if (buy == sell) break;

            while (!st.empty() && prices[st.top().first] >= prices[buy]) {
                auto prev = st.top(); st.pop();
                profits.push_back(prices[prev.second] - prices[prev.first]);
            }

            while (!st.empty() && prices[st.top().second] <= prices[sell]) {
                auto prev = st.top(); st.pop();
                profits.push_back(prices[prev.second] - prices[buy]);
                buy = prev.first;
            }

            st.push({buy, sell});
        }

        while (!st.empty()) {
            auto t = st.top(); st.pop();
            profits.push_back(prices[t.second] - prices[t.first]);
        }

        if (k >= profits.size())
            return accumulate(profits.begin(), profits.end(), 0);

        nth_element(profits.begin(), profits.end() - k, profits.end());
        return accumulate(profits.end() - k, profits.end(), 0);
    }
};
