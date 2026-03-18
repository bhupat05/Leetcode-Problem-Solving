// Last updated: 3/18/2026, 2:21:02 PM
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

        vector<int> diffArray(n + 1, 0);
        for (int i = 0; i < q; i++) {
            diffArray[queries[i][0]] += 1;
            diffArray[queries[i][1] + 1] -= 1;
        }

        int currOperations = 0;
            for (int i = 0; i < n; i++) {
                currOperations += diffArray[i];
                if (currOperations < nums[i]) return false;
            }
        return true;
    }
};