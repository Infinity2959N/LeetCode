class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)   return -1;
        int ans=1;
        int n1= grid.size();
        
        vector<pair<int,int>> directions=
            {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {-1,-1}, {1, -1}, {-1,1}};
        
        queue<pair<int, int>> q;
        q.push({0,0});

        while(!q.empty()){
            int n= q.size();
            for(int i=0; i<n; i++){
                auto [r, c]= q.front();
                if(r==n1-1 && c== n1-1) return ans; //found
                q.pop();

                for(auto [dr, dc]: directions){
                    int cr= dr+r;
                    int cc= dc+c;

                    if(cr>=0 && cr< n1 && cc>=0 && cc< n1 && grid[cr][cc]==0){
                        grid[cr][cc]=1; //mark visited inplace
                        q.push({cr, cc});
                    }
                }
            }
            ans++;
        }
        return -1;  //ans not found
    }
};