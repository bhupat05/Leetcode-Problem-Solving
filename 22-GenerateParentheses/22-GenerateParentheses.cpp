// Last updated: 3/18/2026, 3:03:01 PM
class Solution {
public:
    void solve(int open, int close, int n, string &temp, vector<string>& r) {
        if(open == n && close == n) {
            r.push_back(temp);
            return;
        }

        if(open < n) {
            temp.push_back('(');
            solve(open + 1, close, n, temp, r);
            temp.pop_back();
        }

        if(close < open) {
            temp.push_back(')');
            solve(open , close + 1, n, temp, r);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> r;
        string temp = "";
        solve(0, 0 , n, temp,r);
        return r;
    }
};