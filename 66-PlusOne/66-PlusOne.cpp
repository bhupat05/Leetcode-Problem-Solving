// Last updated: 3/18/2026, 3:02:08 PM
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        

        for(int i = n - 1; i >= 0; i--) {
            if(digits[i] != 9) {
                digits[i] = digits[i] + 1;
                return digits;
            } else {
                if(i == 0) {
                    digits[i] = 0;
                    digits.insert(digits.begin(), 1);
                    return digits;
                } else {
                    digits[i] = 0;
                }
            }


        }
        return digits;
    }
};