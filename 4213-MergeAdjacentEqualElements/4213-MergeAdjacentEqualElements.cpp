// Last updated: 3/18/2026, 2:19:03 PM
class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n = nums.size();
        vector<long long> r;
        long long y = nums[0];
        r.push_back(y);

        for(int i = 1; i < n; i++) {
            int x = nums[i];
            if(x != y) {
                r.push_back(x);
                y = x;
            }
            else {
                while(!r.empty() && r.back() == y) {
                    y = 2 * y;
                    r.pop_back();
                }
                r.push_back(y);
            }
            
        }
        return r;
    }
};