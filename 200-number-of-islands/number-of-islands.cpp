class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        int countIslands=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1'){
                    countIslands++;
                    bfs(grid, i, j, m, n);
                }
            }
        }
        return countIslands;
    }
private:
    void DFS(vector<vector<char>>& grid, int i, int j, int m, int n){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]=='0')   return;
        
        grid[i][j]='0';

        DFS(grid, i-1, j, m, n);
        DFS(grid, i+1, j, m, n);
        DFS(grid, i, j-1, m, n);
        DFS(grid, i, j+1, m, n);
    }

    void bfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
    queue<pair<int, int>> q;
    q.push({i, j});
    grid[i][j] = '0';

    vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1') {
                grid[nx][ny] = '0';
                q.push({nx, ny});
            }
        }
    }
}

};