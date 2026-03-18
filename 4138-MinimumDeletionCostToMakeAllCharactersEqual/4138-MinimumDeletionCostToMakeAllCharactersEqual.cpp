// Last updated: 3/18/2026, 2:19:29 PM
class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        int n = s.length();
        unordered_map<char, long long> mp;

        for(int i = 0; i < n; i++) {
            mp[s[i]] += cost[i];
        }

        long long sum = accumulate(cost.begin(), cost.end(), 0LL); 

        long long result = LLONG_MAX;  

        for(auto& it : mp) {
            result = min(result, sum - it.second);
        }
        return result;
    }
};
