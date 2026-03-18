// Last updated: 3/18/2026, 2:23:42 PM
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = queries.size();
        vector<int> result(n);
        vector<int> queryIndices(n);

        for (int i = 0; i < n; i++) queryIndices[i] = i;

        sort(intervals.begin(), intervals.end());
        sort(queryIndices.begin(), queryIndices.end(), [&](int a, int b){
            return queries[a] < queries[b];
        });

        // minHeap sorted by interval length
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        int IntervalIndex = 0;
        for (int i = 0; i < n; i++) {
            int query = queries[queryIndices[i]];

            while (IntervalIndex < intervals.size() && intervals[IntervalIndex][0] <= query) {
                int left = intervals[IntervalIndex][0];
                int right = intervals[IntervalIndex][1];
                if (right >= query) {
                    minHeap.push({right - left + 1, right});
                }
                IntervalIndex++;
            }

            while (!minHeap.empty() && minHeap.top().second < query) {
                minHeap.pop();
            }

            if (minHeap.empty()) {
                result[queryIndices[i]] = -1;
            } else {
                result[queryIndices[i]] = minHeap.top().first;
            }
        }
        return result;
    }
};
