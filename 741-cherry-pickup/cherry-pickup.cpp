class Solution {
public:
    int n;
    vector<vector<vector<int>>> memo;

    int dfs(vector<vector<int>>& grid, int r1, int c1, int r2) {
        int c2 = r1 + c1 - r2;

        // Bounds check
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n ||
            grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;

        // Reached bottom-right
        if (r1 == n - 1 && c1 == n - 1)
            return grid[r1][c1];

        if (memo[r1][c1][r2] != -1)
            return memo[r1][c1][r2];

        int cherries = 0;

        // Same cell? Only one cherry
        if (r1 == r2 && c1 == c2)
            cherries += grid[r1][c1];
        else
            cherries += grid[r1][c1] + grid[r2][c2];

        // Try all combinations of moves
        int next = max({
            dfs(grid, r1 + 1, c1, r2 + 1),  // down, down
            dfs(grid, r1, c1 + 1, r2),      // right, right
            dfs(grid, r1 + 1, c1, r2),      // down, right
            dfs(grid, r1, c1 + 1, r2 + 1)   // right, down
        });

        if (next == INT_MIN)
            return memo[r1][c1][r2] = INT_MIN;

        return memo[r1][c1][r2] = cherries + next;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        memo = vector(n, vector(n, vector<int>(n, -1)));

        return max(0, dfs(grid, 0, 0, 0)); // Starting from (0,0) for both
    }
};
