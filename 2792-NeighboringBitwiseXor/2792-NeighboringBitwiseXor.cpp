// Last updated: 3/18/2026, 2:22:09 PM
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int x = 0;

        for(int i=0; i<n; i++){
            x = x^derived[i];
        }
        return x == 0;
    }
};