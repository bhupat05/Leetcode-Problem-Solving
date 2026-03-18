// Last updated: 3/18/2026, 2:19:39 PM
class Solution {
public:
    bool Prime(int x) {
        if(x <= 1) return false;

        for(int i = 2; i * i <= x; i++) {
            if(x % i == 0) return false;
        }

        return true;
    }
    bool completePrime(int num) {
        string s = to_string(num);
        int n = s.size();

        for(int i = 1; i <=n; i++) {
            int x = stoi(s.substr(0, i));
            if(!Prime(x)) {
                return false;
            }
        }

        for(int i = 0; i < n; i++) {
            int x = stoi(s.substr(i));
            if(!Prime(x)) {
                return false;
            }
        }

        return true;
        
    }
};