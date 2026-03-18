// Last updated: 3/18/2026, 2:27:44 PM
class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;       
        stack<string> strStack;    
        string current = "";       
        int num = 0;               

        for(char c : s) {

            if(isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            else if(c == '[') {
                numStack.push(num);
                strStack.push(current);

                num = 0;
                current = "";
            }

            else if(c == ']') {
                string temp = current;

                current = strStack.top(); strStack.pop();
                int repeat = numStack.top(); numStack.pop();

                while(repeat--) {
                    current += temp;
                }
            }

            else {
                current += c;
            }
        }

        return current;
    }
};
