// Last updated: 3/18/2026, 2:19:23 PM
class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v;

        for (int i = 0; i < n; i++) {
            
            int x = nums[i];
            string b = "";

            while (x > 0) {
                b += (x % 2) + '0';
                x /= 2;
            }

            reverse(b.begin(), b.end());  

            int r = 0, p = 1;
            
            for (char ch : b) {
                if (ch == '1') r += p;
                p *= 2;
            }

            v.push_back({r, nums[i]}); 
        }

        sort(v.begin(), v.end(), [](auto &p1, auto &p2){
            if (p1[0] != p2[0]) return p1[0] < p2[0];
            return p1[1] < p2[1];
        });

        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = v[i][1];
        }

        return result;
    }
};
