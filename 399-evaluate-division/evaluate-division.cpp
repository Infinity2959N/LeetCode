class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Union Find or Weighted DFS
        // How is this a graph problem: Rule of thumb: If A relates to B and B relates to C, and you want to find how A relates to C, then it is a graph problem
        // If a/b is 2.0, it means when you are at node a and want to go to node b, the cost would be 2.0
        // Inversly, if you want to go from b back to a, the cost will be 1/2.0= 0.5
        // If a/b is 2.0, and b/c is 3/0, a/cc will be 6.0 
        // Why? Travel from a-> b: multiply by 2.0
        // Travel from b->c: multiply by 3.0
        // It is a path finding problem in a directed weighted graph

        unordered_map<string, vector<pair<string, double>>> adj;
        // Map "a"-> {{b, 2.0}, {c, 6.0}}

        // Building the adj, if a/b=2.0 is given, we add two edges: a->{b, 2.0] and b->{a, 1.0/2.0}
        for(int i=0; i<values.size(); i++){
            string u = equations[i][0];
            string v = equations[i][1];
            adj[u].push_back({v, values[i]});
            adj[v].push_back({u, 1.0/values[i]});
        }

        // Now, for each query X/Y, start DFS from X, multiplying values on the way till we reach Y
        // Edge case: If X or Y is not present in map, return -1

        vector<double> ans;
        for(auto &q: queries){
            string x= q[0], y= q[1];
            if(!adj.count(x) || !adj.count(y)) ans.push_back(-1.0);
            else{
                unordered_set<string> visited;  //reset for every iteration
                ans.push_back(dfs(x, y, visited, adj, 1.0));    // 1.0 is initial product
            }
        }
        return ans;
    }
private:
    double dfs(string curr, string target, unordered_set<string>& visited, unordered_map<string, vector<pair<string, double>>>& adj, double product){
        if(curr==target) return product;

        visited.insert(curr);

        for(auto& edge: adj[curr]){
            string neighbor= edge.first;
            double weight= edge.second;
            if(!visited.count(neighbor)){
                double result= dfs(neighbor, target, visited, adj, product*weight);
                if(result!= -1.0) return result;
            }
        }
        return -1.0; // dead end
    }
};