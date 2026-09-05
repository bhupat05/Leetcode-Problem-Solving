// Last updated: 9/5/2026, 11:02:16 PM
1class Solution {
2public:
3    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
4        int n = arr.size();
5        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
6
7        for(int i = 0; i < n; i++) {
8            pq.push({abs(arr[i] - x), arr[i]});
9            
10        }
11        vector<int> r;
12        while(k--) {
13            auto[d, a] = pq.top();
14            pq.pop();
15            r.push_back(a);
16        }
17        sort(r.begin(), r.end());
18        return r;
19    }
20};