// Last updated: 5/20/2026, 9:15:33 AM
1class Solution {
2public:
3    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
4        int n = A.size();
5        vector<int>result(n);
6        unordered_map<int,int>mp;
7        int count = 0;
8        for(int i=0; i<n; i++){
9            mp[A[i]]++;
10            if(mp[A[i]] == 2){
11                count++;
12            }
13
14             mp[B[i]]++;
15             if(mp[B[i]] == 2){
16                count++;
17            }
18
19            result[i] = count;
20        }  
21        return result; 
22        
23    }
24};