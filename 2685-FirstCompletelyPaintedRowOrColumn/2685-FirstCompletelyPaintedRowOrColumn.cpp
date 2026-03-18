// Last updated: 3/18/2026, 2:22:19 PM
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int,int>mp;

        for(int i=0; i<arr.size(); i++){
            mp[arr[i]] = i;
        }

        int minI = INT_MAX;

        
        for(int i=0; i<m; i++){
            int maxI = INT_MIN;

            for(int j=0; j<n; j++){
                int val = mat[i][j];
                int inx = mp[val];
                maxI = max(maxI,inx);
            }

            minI = min(minI,maxI);
        }

        
        for(int i=0; i<n; i++){
            int maxI = INT_MIN;

            for(int j=0; j<m; j++){
                int val = mat[j][i];  
                int inx = mp[val];
                maxI = max(maxI,inx);
            }

            minI = min(minI,maxI);
        }

        return minI;
    }
};
