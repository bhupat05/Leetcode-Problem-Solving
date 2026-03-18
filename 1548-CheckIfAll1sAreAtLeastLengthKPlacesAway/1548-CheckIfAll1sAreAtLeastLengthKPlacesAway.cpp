// Last updated: 3/18/2026, 2:24:26 PM
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int count = 0;
        bool seenFirst = false;   // replaces "first"

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 1) {
                if (seenFirst && count < k) return false;  
                seenFirst = true;
                count = 0;
            } 
            else if (seenFirst) { 
                count++;
            }
        }

        return true;
    }
};
