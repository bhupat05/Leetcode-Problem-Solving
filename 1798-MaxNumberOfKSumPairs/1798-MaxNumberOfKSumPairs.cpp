// Last updated: 3/18/2026, 2:23:57 PM
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int x = k - nums[i];

            if (mp.count(x) != 0) {
                count++;
                mp[x]--;            
                if (mp[x] == 0)     
                    mp.erase(x);
            } else {
                mp[nums[i]]++;
            }
        }

        return count;
    }
};
