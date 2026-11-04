// Last updated: 11/4/2026, 6:55:49 PM
1class Solution {
2    public int[] topKFrequent(int[] nums, int k) {
3        int n = nums.length;
4        Map<Integer, Integer> mp = new HashMap<>();
5        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
6        
7        for(int i = 0; i < n; i++) {
8            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
9        }
10
11        for(Map.Entry<Integer, Integer> entry : mp.entrySet()) {
12            pq.offer(new int[]{entry.getValue(), entry.getKey()});
13            if(pq.size() > k) pq.poll();
14        }
15        int[] result = new int[k];
16        for(int i = 0; i < k; i++) {
17            result[i] = pq.poll()[1];
18        }
19        return result;
20    }
21}