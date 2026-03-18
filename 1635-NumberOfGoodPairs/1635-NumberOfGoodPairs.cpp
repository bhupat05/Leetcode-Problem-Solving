// Last updated: 3/18/2026, 2:24:14 PM
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> freq(101, 0);
        int count = 0;

        for (int x : nums) {
            count += freq[x];
            freq[x]++;
        }

        return count;
    }
};
