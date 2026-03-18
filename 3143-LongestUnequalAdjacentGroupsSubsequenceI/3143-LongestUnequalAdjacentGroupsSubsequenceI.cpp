// Last updated: 3/18/2026, 2:21:59 PM
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        if(n <= 0) return {};
        vector<string>r;
         r.push_back(words[0]);
         int x = groups[0];
        for(int i=1; i<n; i++){
            if(groups[i] != x){
                r.push_back(words[i]);
                x = groups[i];
            }
            

        }
        return r;

    }
   
};