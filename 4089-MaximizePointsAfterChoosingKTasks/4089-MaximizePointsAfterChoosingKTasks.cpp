// Last updated: 3/18/2026, 2:19:42 PM
class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n = technique1.size();
        long long sum = 0;

        for (int x : technique1) {
            sum += x;
        } 

        vector<pair<int,int>> vec(n);
        for (int i = 0; i < n; i++) {
          vec[i] = { technique1[i], technique2[i] };  
        } 

        sort(vec.begin(), vec.end(),
            [](const pair<int,int>& a, const pair<int,int>& b) {
                return (a.second - a.first) > (b.second - b.first);
            }
        );

        int N = n - k;
        for (int i = 0; i < N; i++) {
            int extra = vec[i].second - vec[i].first;
            if (extra > 0) sum += extra;
            else break; 
        }

        return sum;
    }
};
