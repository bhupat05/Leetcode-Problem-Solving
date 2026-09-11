// Last updated: 9/11/2026, 5:21:16 PM
1class Solution {
2public:
3    int scheduleCourse(vector<vector<int>>& courses) {
4        int n = courses.size();
5        sort(courses.begin(), courses.end(), [](vector<int> &a, vector<int> &b){return a[1] < b[1];});
6        priority_queue<int> pq;
7        int time = 0;
8
9        for(auto course : courses) {
10            pq.push(course[0]);
11            time += course[0];
12
13            if(time > course[1]) {
14                time -= pq.top();
15                pq.pop();
16            }
17        }
18        return pq.size();
19    }
20};