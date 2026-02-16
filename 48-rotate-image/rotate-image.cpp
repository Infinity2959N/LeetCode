class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Transpose + reverse
        int n= matrix.size();
        
        // Transpose
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int temp= matrix[i][j];
                matrix[i][j]= matrix[j][i];
                matrix[j][i]= temp;
            }
        }

        // Row-wise reverse
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};