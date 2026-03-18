// Last updated: 3/18/2026, 2:20:21 PM
class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        const long long MOD = 1e9 + 7;


        int count = 0;

        for(int i = 1; i < n; i++) {
            if(complexity[i] <= complexity[0]) {
                return 0;
            } 

            count++;
        }

        long long fact = 1;

        for(int i = 1; i <= count; i++) {
            fact = (fact * i) % MOD;
        }
        return fact;
    }
};