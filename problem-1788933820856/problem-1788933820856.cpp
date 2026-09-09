// Last updated: 9/9/2026, 11:33:40 AM
1class Twitter {
2public:
3    unordered_map<int, unordered_set<int>> follower;
4    unordered_map<int, vector<pair<int, int>>> post;
5    int cnt = 0;
6    Twitter() {
7        
8    }
9    
10    void postTweet(int userId, int tweetId) {
11        post[userId].push_back({cnt++, tweetId});
12    }
13    
14    vector<int> getNewsFeed(int userId) {
15        priority_queue<pair<int, int>> pq;
16        for(auto [x, id] : post[userId]) {
17            pq.push({x, id});
18            // if(pq.size() > 10) pq.pop();
19        }
20        for(int idx : follower[userId]) {
21            for(auto[x, id] : post[idx]) {
22                pq.push({x, id});
23                // if(pq.size() > 10) pq.pop();
24            }
25        }
26        vector<int> r;
27        int c = 10;
28        while(!pq.empty() && c) {
29            auto[x, id] = pq.top();
30            pq.pop();
31            r.push_back(id);
32            c--;
33        }
34        return r;
35    }
36    
37    void follow(int followerId, int followeeId) {
38        follower[followerId].insert(followeeId);
39    }
40    
41    void unfollow(int followerId, int followeeId) {
42        follower[followerId].erase(followeeId);
43    }
44};
45
46/**
47 * Your Twitter object will be instantiated and called as such:
48 * Twitter* obj = new Twitter();
49 * obj->postTweet(userId,tweetId);
50 * vector<int> param_2 = obj->getNewsFeed(userId);
51 * obj->follow(followerId,followeeId);
52 * obj->unfollow(followerId,followeeId);
53 */