class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m= matrix.size(), n= matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        int maxLen=0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int len= dfs(m, n, i, j, matrix, dp);
                if(len> maxLen) maxLen= len;
            }
        }

        return maxLen;
    }
private: 
    int dfs(int m, int n, int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(dp[i][j]!= -1)   return dp[i][j];

        int best= 1; //Atleast the node itself

        int dirs[4][2]= {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for(int d=0; d<4; d++){
            int x= i+ dirs[d][0];
            int y= j+ dirs[d][1];

            if(x>=0 && y>=0 && x<m && y<n && matrix[x][y] > matrix[i][j]){
                int len= 1+ dfs(m, n, x, y, matrix, dp);
                if(best< len)   best=len;
            }
        }
        return dp[i][j]= best;
    }
};