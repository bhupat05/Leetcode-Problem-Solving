// Last updated: 3/18/2026, 2:28:56 PM
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        for(auto pair : mp){
            if(pair.second > 1) return true;
        }
        return false;
    }
};