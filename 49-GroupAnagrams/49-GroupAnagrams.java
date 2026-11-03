// Last updated: 11/3/2026, 11:33:04 AM
1class Solution {
2    public List<List<String>> groupAnagrams(String[] strs) {
3        Map<String, List<String>> ans = new HashMap<>();
4
5        for(String s : strs) {
6            char[] chars = s.toCharArray();
7            Arrays.sort(chars);
8            String key = new String(chars);
9            if(!ans.containsKey(key)) {
10                ans.put(key, new ArrayList<>());
11            }
12            ans.get(key).add(s);
13        }
14        return new ArrayList<>(ans.values());
15    }
16}