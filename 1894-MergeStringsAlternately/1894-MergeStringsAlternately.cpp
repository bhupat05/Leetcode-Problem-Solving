// Last updated: 3/18/2026, 2:23:46 PM
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        int i=0,j=0;
        string r = "";
        

        while(i<m && j<n){
           r += word1[i];
           r +=word2[j];
           i++;
           j++;
           
        }

        while(i<m ) {
            r += word1[i];
            i++;
        }
        while(j<n ) {
            r += word2[j];
            j++;
        }
        return r;
    }
};