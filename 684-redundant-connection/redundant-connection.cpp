class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();
        vector<int> rank(n+1,0);
        vector<int> parent(n+1);
        for(int i=0; i<n+1; i++) parent[i]=i;

        for(int i=0; i<n; i++){
            int a= edges[i][0];
            int b= edges[i][1];
            if(unite(a, b, rank, parent)){
                return {a,b};
            }
        }
        return {-1, -1};
    }
private:
    int find(int x, vector<int>& parent){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x], parent);
    }
    bool unite(int x, int y, vector<int>& rank, vector<int>& parent){
        int parent_x= find(x, parent);
        int parent_y= find(y, parent);

        if(parent_x !=parent_y){
            if(rank[parent_x]> rank[parent_y]){
                rank[parent_x]++;
                parent[parent_y]= parent_x;
            }else{  // smaller or equal rank of x wrt y
                rank[parent_y]++;
                parent[parent_x]= parent_y;
            }
            return false;
        }
        else
            return true;
    }
};