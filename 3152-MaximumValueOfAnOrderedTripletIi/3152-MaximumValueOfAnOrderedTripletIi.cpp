// Last updated: 3/18/2026, 2:21:58 PM
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;  // If there are less than 3 elements, return 0

        // Compute prefix maximum array
        vector<int> prefix_max(n);
        prefix_max[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix_max[i] = max(prefix_max[i - 1], nums[i]);
        }

        // Compute suffix maximum array
        vector<int> suffix_max(n);
        suffix_max[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix_max[i] = max(suffix_max[i + 1], nums[i]);
        }

        // Compute the maximum triplet value
        long long max_result = 0;  // Use long long to handle large values
        for (int j = 1; j < n - 1; j++) {
            int max_i = prefix_max[j - 1];  // Best nums[i] for i < j
            int max_k = suffix_max[j + 1];  // Best nums[k] for k > j
            long long result = (long long)(max_i - nums[j]) * max_k;  // Avoid integer overflow
            max_result = max(max_result, result);
        }

        return max_result;
    }
};



