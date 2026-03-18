// Last updated: 3/18/2026, 2:27:56 PM
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        for(auto it : mp) {
            int a = it.first;
            int b = it.second;

            pq.push({b, a});
        }

        vector<int> r;

        while(k--) {
            int a = pq.top().second;
            pq.pop();
            r.push_back(a);
        } 
        return r;
    }
};