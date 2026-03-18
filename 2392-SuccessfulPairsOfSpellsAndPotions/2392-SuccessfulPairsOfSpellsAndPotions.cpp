// Last updated: 3/18/2026, 2:22:47 PM
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();

        vector<int> result;

        for(long long s : spells) {
            long long need = (success + s - 1) / s;  
            
            int idx = lower_bound(potions.begin(), potions.end(), need) - potions.begin();

            int count = m - idx;
            result.push_back(count);
        }

        return result;
    }
};