// Last updated: 6/28/2026, 6:57:03 AM
1class RecentCounter {
2    Queue<Integer> q = new LinkedList<>();
3    public RecentCounter() {
4        
5    }
6    
7    public int ping(int t) {
8        q.add(t);
9        while(!q.isEmpty() && q.peek() < t - 3000) {
10            q.poll();
11        } 
12        return q.size();
13    }
14}
15
16/**
17 * Your RecentCounter object will be instantiated and called as such:
18 * RecentCounter obj = new RecentCounter();
19 * int param_1 = obj.ping(t);
20 */