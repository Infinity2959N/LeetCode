class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Build graph
        vector<vector<pair<int, int>>> graph(n);
        for(auto& flight: flights){
            int from= flight[0], to= flight[1], price= flight[2];
            graph[from].push_back({to, price});
        }

        // Min heap:
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, src, 0});

        // Dist and stop matrix:
        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));

        // Path finder:
        while(!pq.empty()){
            auto [cost, node, stops]= pq.top();
            pq.pop();

            if(node==dst)   return cost;

            if(stops>k) continue;

            for(auto&[next, price]: graph[node]){
                int newCost= cost+price;
                if(newCost< dist[next][stops+1]){
                    dist[next][stops+1]= newCost;
                    pq.push({newCost, next, stops+1});
                }
            }
        }
        return -1;
    }
};