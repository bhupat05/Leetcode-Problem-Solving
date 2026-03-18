// Last updated: 3/18/2026, 2:25:11 PM
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> r;

        sort(arr.begin(), arr.end());

        int mini = INT_MAX;

        for(int i = 1; i < n; i++) {
            mini = min(mini, abs(arr[i] - arr[i - 1]));
        }

        for(int i = 1; i < n; i++) {
            if(abs(arr[i] - arr[i - 1]) == mini) {
                int a = max(arr[i], arr[i - 1]);
                int b = min(arr[i], arr[i - 1]);
                r.push_back({b, a});
            }
        }

        return r;

       
    }
};