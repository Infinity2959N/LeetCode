class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        // dp[k][i][j] -> max cherries collected when:
        // Person A is at (i, k - i) and Person B is at (j, k - j)
        vector<vector<vector<int>>> dp(2 * n - 1,
            vector<vector<int>>(n, vector<int>(n, -1)));

        dp[0][0][0] = grid[0][0];

        for (int k = 1; k < 2 * n - 1; ++k) {
            for (int i = max(0, k - (n - 1)); i <= min(n - 1, k); ++i) {
                for (int j = max(0, k - (n - 1)); j <= min(n - 1, k); ++j) {
                    int r1 = i, c1 = k - i;
                    int r2 = j, c2 = k - j;

                    if (grid[r1][c1] == -1 || grid[r2][c2] == -1)
                        continue;

                    int max_prev = -1;
                    for (int pi = r1 - 1; pi <= r1; ++pi) {
                        for (int pj = r2 - 1; pj <= r2; ++pj) {
                            if (pi >= 0 && pj >= 0 &&
                                dp[k - 1][pi][pj] != -1) {
                                max_prev = max(max_prev, dp[k - 1][pi][pj]);
                            }
                        }
                    }

                    if (max_prev == -1)
                        continue;

                    int cherries = grid[r1][c1];
                    if (r1 != r2 || c1 != c2)
                        cherries += grid[r2][c2];

                    dp[k][r1][r2] = max_prev + cherries;
                }
            }
        }

        return max(0, dp[2 * n - 2][n - 1][n - 1]);
    }
};
