// Last updated: 3/18/2026, 2:21:37 PM
class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        for(auto & p : mp) {
            if(p.second > 2) return false;
        }
        return true;
    }
};