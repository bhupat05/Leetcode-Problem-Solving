// Last updated: 3/18/2026, 2:25:32 PM
class Solution {
public:
    char dfs(unordered_map<char,vector<char>>&adj,char ch,vector<int>&visited){
        visited[ch -'a'] = 1;
        char minchar = ch;
        for(char &v : adj[ch]){
            if(visited[v-'a'] == 0){
                minchar = min(minchar,dfs(adj,v,visited));
            }
        }
        return minchar;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        int m = baseStr.length();
        unordered_map<char,vector<char>>adj;

        for(int i=0; i<n; i++){
            char u = s1[i]; 
            char v = s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);    
        }      

        string r;
        for(int i=0; i<m; i++){
            char ch = baseStr[i];
            vector<int>visited(26,0);
            char minchar = dfs(adj,ch,visited);
            r.push_back(minchar);
        }
        return r;
    }
};