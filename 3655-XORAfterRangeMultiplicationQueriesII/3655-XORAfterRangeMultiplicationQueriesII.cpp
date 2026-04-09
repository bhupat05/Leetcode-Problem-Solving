// Last updated: 4/9/2026, 12:59:30 PM
1class Solution {
2public:
3    // calc  v ^ md-2
4    long long binpow(long long a,long long e,int md){
5        long long res = 1;
6        while(e>0){
7            if(e&1){
8                res = (res*a)%md;
9            }
10            a = (a*a)%md;
11            e>>=1;
12        }
13        return res;
14    }
15    long long mdinv(long long n, int md){
16        return binpow(n,md-2,md);
17    }
18    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
19        int n = nums.size(), md = 1e9 + 7;
20        int limit = sqrt(n); 
21        // group by values of k , k = > key ; l,r,v = >values 
22        unordered_map<int, vector<vector<int>>> mp;
23        for(int i=0;i<queries.size();i++){
24            int l = queries[i][0], r = queries[i][1], k = queries[i][2], v = queries[i][3];
25            if(k>=limit){
26                for(int j=l;j<=r;j+=k){
27                    nums[j] = ((long long)nums[j]*v)%md;
28                }
29            }else{
30                mp[k].push_back(queries[i]);
31            }
32        }
33
34        for(auto &[k,query] : mp){
35            vector<long long> diff(n,1);
36            for(auto &q : query){
37                int l = q[0], r = q[1], v = q[3];
38                diff[l] = (diff[l]*v)%md;
39                int steps = (r-l)/k;
40                int next = l + (steps + 1)*k;
41                if(next < n){
42                    diff[next] = (diff[next] * mdinv(v,md))%md;
43                }
44            }
45            //find prefix array to get all the multipliers
46            for(int i=0;i<n;i++){
47                if(i>=k) diff[i] = (diff[i] * diff[i-k])%md;
48                nums[i] = ((long long)nums[i]*diff[i])%md;
49            }
50        }
51
52        int ans = 0;
53        for(auto x : nums) ans = ans^x;
54        return ans;  
55    }
56};