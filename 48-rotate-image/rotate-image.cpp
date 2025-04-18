class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){   //1) transpose the matrix, 2)reverse the matrix
            for(int j=0;j<i && j<m;j++){
                int temp;
               swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m/2;j++){
                swap(matrix[i][j],matrix[i][m-1-j]);
            }
        }
    }
};