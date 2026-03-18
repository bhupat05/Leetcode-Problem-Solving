// Last updated: 3/18/2026, 2:23:13 PM
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int,int>mp;
        vector<int>v;
        for(int i=0; i<digits.size(); i++){
            mp[digits[i]]++;
        }

        for(int i=1; i<=9; i++){
            if(mp[i] == 0) continue;
            mp[i]--;
            for(int j=0; j<=9; j++){
                if(mp[j] == 0) continue;
                mp[j]--;
                for(int k=0; k<=8; k += 2){
                    if(mp[k] == 0) continue;
                    mp[k]--;
                    int num = (i*100)+(j*10)+(k);
                    v.push_back(num);
                    mp[k]++;
                }
                mp[j]++;
            }
            mp[i]++;
        }
        return v;
    }
};