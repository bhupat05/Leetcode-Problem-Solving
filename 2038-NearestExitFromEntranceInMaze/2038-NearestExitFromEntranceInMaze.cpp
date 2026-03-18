// Last updated: 3/18/2026, 2:23:33 PM
class Solution {
public:
    vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});

        maze[entrance[0]][entrance[1]] = '+';   

        int steps = 0;

        while(!q.empty()) {

            int sz = q.size();
            while(sz--) {

                auto [x, y] = q.front();
                q.pop();

                if(!(x == entrance[0] && y == entrance[1]) &&
                   (x == 0 || x == m-1 || y == 0 || y == n-1)) {
                    return steps;
                }

                for(auto &d : directions) {
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if(nx >= 0 && nx < m && ny >= 0 && ny < n &&
                       maze[nx][ny] == '.') {

                        maze[nx][ny] = '+'; 
                        q.push({nx, ny});
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};
