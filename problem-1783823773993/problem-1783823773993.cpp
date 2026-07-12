// Last updated: 7/12/2026, 8:06:13 AM
1class Solution {
2public:
3    int secondsBetweenTimes(string startTime, string endTime) {
4
5        string a = startTime.substr(0, 2);
6        string b = startTime.substr(3, 2);
7        string c = startTime.substr(6, 2);
8
9        string d = endTime.substr(0, 2);
10        string e = endTime.substr(3, 2);
11        string f = endTime.substr(6, 2);
12
13        int x = stoi(a) * 3600 + stoi(b) * 60 + stoi(c);
14        int p = stoi(d) * 3600 + stoi(e) * 60 + stoi(f);
15
16        return p - x;
17    }
18};