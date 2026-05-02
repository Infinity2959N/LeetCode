class DSU{
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n){
        parent.resize(n);
        rank.assign(n, 0);  // rank is 0 by default
        for(int i=0; i<n; i++) parent[i]= i;    // each node is it's parent by default
    }

    int find(int i){
        if(parent[i]==i) return i;
        return parent[i]= find(parent[i]); // Path compression
    }

    bool unite(int i, int j){
        int root_i= find(i);
        int root_j= find(j);

        if(root_i!= root_j){
            // union by rank
            if(rank[root_i]< rank[root_j]){
                parent[root_i]= root_j;
            }else if(rank[root_i]> rank[root_j]){
                parent[root_j]= root_i;
            }else{
                parent[root_j]= root_i;
                rank[root_i]++;
            }
            return true;
        }
        return false;
    }
};


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // MST
        // Either Kruskal's or Prims
        // MST: sort by weights, use DSU to join
        vector<tuple<int, int, int>> edgeList;
        // Treat each coordinate as a point, we need N(N-1)/2 edges

        for(int i=0; i<points.size(); i++){
            for(int j=i+1; j<points.size(); j++){
                int dist= abs(points[i][0]- points[j][0])+ abs(points[i][1]- points[j][1]);
                edgeList.push_back({dist, i, j});   // i and j are indices of coordinates
            }
        }

        sort(edgeList.begin(), edgeList.end());

        int totalCost= 0, edgesCount=0, n=points.size();

        DSU dsu(n);

        for(auto &[weight, i, j]: edgeList){
            if(dsu.unite(i, j)){
                totalCost+=weight;
                edgesCount++;
                if(edgesCount==n-1) break;
            }
        }
        return totalCost;
    }
};