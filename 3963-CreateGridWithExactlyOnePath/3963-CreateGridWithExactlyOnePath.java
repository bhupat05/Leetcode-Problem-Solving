// Last updated: 10/27/2026, 2:43:23 PM
1class Solution {
2    public String[] createGrid(int m, int n) {
3        String[] grid = new String[m];
4        Arrays.fill(grid, "#".repeat(n - 1) + ".");
5        grid[0] = ".".repeat(n);
6        return grid;
7    }
8}