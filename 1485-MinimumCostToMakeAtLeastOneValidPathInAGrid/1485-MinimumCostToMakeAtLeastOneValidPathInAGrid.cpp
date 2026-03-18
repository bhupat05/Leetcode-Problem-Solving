// Last updated: 3/18/2026, 2:24:40 PM
class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};  

    int minCost(vector<vector<int>>& grid) {
         int m = grid.size();
         int n = grid[0].size();  

         priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;  // n

         vector<vector<int>> result(m, vector<int>(n, INT_MAX));  

         result[0][0] = 0;  

         pq.push({0, 0, 0});  

         while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int currcost = curr[0];
            int i = curr[1];
            int j = curr[2];

            for(int k = 0; k < 4; k++){ 
                int i_ = i + dir[k][0];  
                int j_ = j + dir[k][1];  

                if(i_ >= 0 && j_ >= 0 && i_ < m && j_ < n){  
                   int griddir = grid[i][j]; 
                   int dircost = (griddir - 1 == k) ? 0 : 1;  
                   int newcost = currcost + dircost;

                   if(newcost < result[i_][j_]){  
                        result[i_][j_] = newcost;
                        pq.push({newcost, i_, j_});
                   } 
                }
            }
         }

         return result[m-1][n-1];  // Return the cost to reach the bottom-right corner
    }
};
