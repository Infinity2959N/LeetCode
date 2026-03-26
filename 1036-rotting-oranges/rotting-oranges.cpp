class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh=0;
        int m=grid.size(), n= grid[0].size();
        queue<pair<int, int>> rotten;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1)
                    fresh++;
                if(grid[i][j]==2)   
                    rotten.push({i,j});
            }
        }
        if(fresh==0)    return 0;

        set<pair<int, int>> directions={{0,1}, {0,-1}, {1,0}, {-1,0}};

        int time= 0;

        while(!rotten.empty()){
            // For each second we process every rotten currently in the queue
            int size= rotten.size();
            for(int i=0; i<size; i++){
                auto [x,y]= rotten.front();
                rotten.pop();
                for(auto& [xi, yi] : directions){
                    int xd=x+xi;
                    int yd=y+yi;
                    if(xd>=0 && xd<m && yd>=0 && yd<n && grid[xd][yd]==1){
                        fresh--;
                        grid[xd][yd]=2;
                        rotten.push({xd, yd});
                    }
                }
            }
            time++;
            if(fresh==0)    break;
        }

        return fresh==0? time: -1;
    }
};