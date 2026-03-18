// Last updated: 3/18/2026, 2:23:08 PM
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();

        if(n%2 != 0) return false;

        stack<int> s1;
        stack<int> s2;

        for(int i=0; i<n; i++){
            if(locked[i] == '0'){
                s2.push(i);
            }
            else if(s[i] == '('){
                s1.push(i);
            }
            else if(s[i] == ')'){
                if(!s1.empty()){
                    s1.pop();
                }
                else if(!s2.empty()){
                    s2.pop();
                }
                else{
                    return false;
                }
            }
        }

        while(!s1.empty() && !s2.empty() && s1.top()<s2.top()){
            s1.pop();
            s2.pop();

        }
        return s1.empty();



    }
};