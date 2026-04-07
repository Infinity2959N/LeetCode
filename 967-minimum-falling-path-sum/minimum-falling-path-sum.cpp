class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // observation: start at any element in first row
        // can move either below, left diagonal or right diagonal
        // A top to down approach is perfectly valid, just gotta keep check of the left diagonal in a variable, but bottom to up is generally cleaner
        int n= matrix.size();
        vector<int> dp(n);
        for(int i=0; i<n; i++)  dp[i]= matrix[n-1][i];  // Fill with last elements

        for (int i = n - 2; i >= 0; i--) {
            int prev_left = dp[0]; // Store the original dp[j-1]
            for (int j = 0; j < n; j++) {
                int temp = dp[j]; // The "bottom" value before we overwrite it
                
                int bottom = dp[j];
                int bottom_left = (j > 0) ? prev_left : INT_MAX;
                int bottom_right = (j < n - 1) ? dp[j + 1] : INT_MAX;
                
                dp[j] = matrix[i][j] + min({bottom, bottom_left, bottom_right});
                prev_left = temp; // This temp becomes the 'bottom_left' for the next 'j'
            }
        }
        return *min_element(dp.begin(), dp.end());
    }
};