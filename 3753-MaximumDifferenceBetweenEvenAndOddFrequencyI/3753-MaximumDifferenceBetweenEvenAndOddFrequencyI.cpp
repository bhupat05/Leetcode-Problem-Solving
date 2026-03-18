// Last updated: 3/18/2026, 2:20:48 PM
class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> mp;
        for(char c : s){
            mp[c]++;
        }

        int maxOdd = INT_MIN;
        int minEven = INT_MAX;

        for(auto& [ch, freq] : mp){
            if(freq % 2 == 0){
                minEven = min(minEven, freq);
            } else {
                maxOdd = max(maxOdd, freq);
            }
        }

        // Constraints ensure at least one odd and one even freq exist
        return maxOdd - minEven;
    }
};
