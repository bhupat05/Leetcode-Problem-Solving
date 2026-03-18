// Last updated: 3/18/2026, 3:02:46 PM
class Solution {
public:
    int longestValidParentheses(string s) {
        int l=0;
        int r=0;
        int max_l=0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(')
            l++;
            else
            r++;
            if(l == r){
                max_l = max(max_l,2*l);
            }
            else if(r>l)
           {
             l=0;
            r=0;
           }
        }
        l=0;
        r=0;
         for(int i=s.length()-1; i>=0; i--){
            if(s[i] == '(')
            l++;
            else
            r++;
            if(l == r){
                max_l = max(max_l,2*l);
            }
            else if(r<l)
           {
             l=0;
            r=0;
           }
        }
        return max_l;
        
    }
};