class DSU{
public:
    vector<int> parent;
    DSU(int n){
        parent.resize(n+1);
        for(int i=0; i<n+1; i++)    parent[i]= i;
    }
    int find(int i){
        if(parent[i]==i)    return i;
        return parent[i]= find(parent[i]);  //path compression
    }
    void unite(int i, int j){
        int root_i= find(i);
        int root_j= find(j);
        if(root_i!=root_j)  parent[root_i]= root_j;
    }
};


class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        // If a divisor z is greater than threshold, then all multiples of  share z aa common divisor

        // Algorithm: Initialize DSU with n+1 nodes
        //start z= threshold+1 upto n
        // For each z, call a nested loop for all it's multiples: dsu.unite(z,m)
        // Answer query by returning dsu.find(A)==dsu.find(B)
    
        DSU dsu(n);

        // 1. The sieve, connect all multiples of divisor> threshold
        for(int z= threshold+1; z<=n; z++){
            // Multiples 2z, 3z, 4z..
            for(int m= 2*z; m<=n; m+=z){
                dsu.unite(z, m);
            }
        }

        // 2. THE QUERY: Constant time lookups
        vector<bool> result;
        for (auto& q : queries) {
            if (dsu.find(q[0]) == dsu.find(q[1])) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
        return result;
    }
};