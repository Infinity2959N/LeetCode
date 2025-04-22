class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // We use multi source BFS here, taking in all the 0s as the source. (As 0s are fewer)
        queue<pair<int, int>> q;
        for(int i=0; i< mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j]==0){
                    q.push({i, j});
                }else{
                    mat[i][j]= -1;  //to indicate unvisited
                }
            }
        }
        bfs(mat, q);

        return mat;
    }
private:
    void bfs(vector<vector<int>>& mat, queue<pair<int, int>> q){
        vector<pair<int, int>> dir={{1,0}, {-1,0}, {0,1}, {0,-1}};
        int rows= mat.size();
        int cols= mat[0].size();

        while(!q.empty()){
            auto [r, c]= q.front();
            q.pop();

            for(auto [dr, dc]: dir){
                int nr= r+dr;
                int nc= c+dc;
                
                if(nr>=0 && nr < rows && nc>=0 && nc< cols && mat[nr][nc]==-1){
                    mat[nr][nc]= mat[r][c]+1;
                    q.push({nr, nc});   // for next level.
                }
            }
        }
    }
};