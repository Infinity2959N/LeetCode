class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> prevRow;

        for(int i=0; i<numRows; i++){
            vector<int> currRow(i+1, 1);
            for(int j=1; j<i; j++){
                currRow[j]= prevRow[j-1]+ prevRow[j];
            }

            res.push_back(currRow);
            prevRow= currRow;
        }
        return res;
    }
};