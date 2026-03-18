// Last updated: 3/18/2026, 2:27:25 PM
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        string s = "";
        int count = 1;

        s += chars[0];  

        for(int i = 1; i < n; i++) {
            if(chars[i] == chars[i - 1]) {
                count++;           
            } else {
                if(count > 1) {
                    s += to_string(count);  
                }
                s += chars[i];   
                count = 1;       
            }
        }

        if(count > 1) {
            s += to_string(count);
        }

        for(int i = 0; i < s.size(); i++) {
            chars[i] = s[i];
        }

        return s.size();
    }
};
