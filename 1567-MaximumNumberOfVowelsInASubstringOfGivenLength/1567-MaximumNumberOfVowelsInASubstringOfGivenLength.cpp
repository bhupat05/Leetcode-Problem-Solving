// Last updated: 3/18/2026, 2:24:22 PM
class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int l = 0;
        int c = 0;

        for(int i = 0; i < k; i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            c++;
        }

        int result = c;

        for(int i = k; i < n; i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            c++;
           
            if(s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u')
            c--;

            result = max(result, c);
            l++;
        }

        
        return result;
        
    }
};