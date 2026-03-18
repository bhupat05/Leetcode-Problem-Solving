// Last updated: 3/18/2026, 2:22:50 PM
class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int n = nums.size();

        int mindis = INT_MAX;
        int val = 0;

        for(int i=0; i<n; i++){
            int dis = abs(nums[i]);
            mindis = min(mindis,dis);
        }

        for(int i : nums){
            if(i == mindis) return mindis;
        }
        return -mindis;
    }
};