class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows= isWater.size();
        int cols= isWater[0].size();

        vector<vector<int>> heights(rows, vector<int>(cols, -1));
        
        queue<pair<int, int>>q;
        for(int i=0; i<isWater.size(); i++){
            for(int j=0; j<isWater[0].size(); j++){
                if(isWater[i][j]==1){
                    heights[i][j]=0;
                    q.push({i, j});
                }
            }
        }
        bfs(heights, q);
        return heights;
    }
private:
    void bfs(vector<vector<int>>& heights, queue<pair<int, int>> q){
        int rows= heights.size();
        int cols= heights[0].size();

        vector<pair<int, int>> directions= {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!q.empty()){
            auto [cr, cc]= q.front();
            q.pop();
            for(auto [dr, dc]: directions){
                int nr= cr+dr;
                int nc= cc+dc;
                if(nr>=0 && nr< rows && nc>=0 && nc<cols && heights[nr][nc]==-1){
                    heights[nr][nc]=heights[cr][cc]+1;
                    q.push({nr, nc});
                }
            }
        }
    }
};