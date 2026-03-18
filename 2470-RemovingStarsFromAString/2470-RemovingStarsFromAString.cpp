// Last updated: 3/18/2026, 2:22:39 PM
class Solution {
public:
    string removeStars(string s) {
        string r = ""; 

        for(char c : s) {
            if(c != '*')
                r.push_back(c);  
            else
                r.pop_back();   
        }

        return r; 
    }
};
