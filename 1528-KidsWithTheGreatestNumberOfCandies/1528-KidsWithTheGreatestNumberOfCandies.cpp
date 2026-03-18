// Last updated: 3/18/2026, 2:24:31 PM
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int maxi = *max_element(candies.begin(), candies.end());
        vector<bool> result(n, false);

        for(int i = 0; i < n; i++) {
            if(candies[i] + extraCandies >= maxi) {
                result[i] = true;
            }
        }
        return result;
    }
};