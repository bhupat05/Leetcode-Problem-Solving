// Last updated: 3/18/2026, 2:23:38 PM
class Solution {
public:
    void solve(vector<vector<int>>& grid, int i, int j, priority_queue<long long>& pq) {
        int m = grid.size();
        int n = grid[0].size();

        for(int k = 1; k < max(m,n); k++) {

            if((i-k) < 0 || (j-k) < 0 || (i+k) >= m || (j+k) >= n) break;

            long long sum = 0;

            int r = i - k, c = j;

            for(int t = 0; t < k; t++) {
                sum += grid[r + t][c + t];
            }

            r = i; c = j + k;
            for(int t = 0; t < k; t++) {
                sum += grid[r + t][c - t];
            }

            r = i + k; c = j;
            for(int t = 0; t < k; t++) {
                sum += grid[r - t][c - t];
            }

            r = i; c = j - k;
            for(int t = 0; t < k; t++) {
                sum += grid[r - t][c + t];
            }

            pq.push(sum);
        }
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<long long> pq;   
        unordered_set<long long> st;    

        for(int i = 1; i < m - 1; i++) {
            for(int j = 1; j < n - 1; j++) {
                solve(grid, i, j, pq);
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                pq.push(grid[i][j]);
            }
        }

        vector<int> ans;
        int cnt = 3;

        while(!pq.empty() && cnt) {
            long long a = pq.top();   
            pq.pop();

            if(!st.count(a)) {
                ans.push_back(a);
                cnt--;
            }
            st.insert(a);
        }

        return ans;
    }
};