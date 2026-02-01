class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Staircase search: Start from the top left
        // if element smaller, move left, if larger, move down
        int r= 0, c= matrix[0].size()-1;

        while(r>-1 && r< matrix.size() && c>-1 && c< matrix[0].size()){
            if(matrix[r][c]== target)
                return true;
            else if(matrix[r][c]< target){
                r++;
            }else{
                c--;
            }
        }
        return false;
    }
};