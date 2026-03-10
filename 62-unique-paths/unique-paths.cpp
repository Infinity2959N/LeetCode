class Solution {
public:
    int uniquePaths(int m, int n) {
        // Using DP: Optimized for O(n) space
        vector<int> row(n, 1);  // 1 way to move in every column in the first row

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                row[j]= row[j]+row[j-1];    // paths[i,j]= paths[i-1,j]+paths[i,j-1]
            }
        }
        return row[n-1];
    }
};