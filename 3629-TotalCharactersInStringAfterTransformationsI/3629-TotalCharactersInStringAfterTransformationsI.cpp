// Last updated: 3/18/2026, 2:21:06 PM
class Solution {
public:
    const int M = 1e9 + 7;
    
    int lengthAfterTransformations(string s, int t) {
        using namespace std;

        vector<long long> freq(26, 0); 

        for (char c : s) {
            freq[c - 'a']++;
        }

        
        for (int i = 0; i < t; ++i) {
            vector<long long> next(26, 0);

            for (int j = 0; j < 26; ++j) {
                if (j < 25) {
                    next[j + 1] = (next[j + 1] + freq[j]) % M;
                } else {
                    
                    next[0] = (next[0] + freq[j]) % M;
                    next[1] = (next[1] + freq[j]) % M;
                }
            }

            freq = next;
        }

        
        long long result = 0;
        for (int i = 0; i < 26; ++i) {
            result = (result + freq[i]) % M;
        }

        return static_cast<int>(result);
    }
};
