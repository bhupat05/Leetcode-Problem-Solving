// Last updated: 3/18/2026, 2:21:23 PM
class Solution {
public:
    int minimumLength(string s) {
        vector<int> v(26,0);
        for(char & ch:s){
            v[ch - 'a']++;
        }

        int result = 0;
        for(int i =0; i<26; i++){
            if(v[i] == 0){
                continue;
            }
            if(v[i]%2 == 0){
                result += 2;
            }
            else{
                result += 1;
            }
        }
        return result;
    }
};