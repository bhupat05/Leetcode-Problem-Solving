// Last updated: 3/18/2026, 2:24:36 PM
class Solution {
public:
    string ans = "";
    int count = 0;

    void solve(int n, int k, string curr) {
        if(curr.size() == n) {
            count++;
            if(count == k) {
                ans = curr;
            }
            return;
        }

        for(char ch : {'a','b','c'}) {
            if(curr.empty() || curr.back() != ch) {
                solve(n, k, curr + ch);
                if(ans != "") return;
            }
        }
    }

    string getHappyString(int n, int k) {
        solve(n, k, "");
        return ans;
    }
};