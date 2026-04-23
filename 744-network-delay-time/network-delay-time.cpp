class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // To start with times[k], which is essentially the source
        // To find the minimum time it takes to reach the furthest node
        // Dijkstra: We use a priority queue
        // Initially, distance of each element from u will be infinity, update the distance 
        // 1. Build the Adjacency List (Source -> {Neighbor, Weight})
        
        vector<vector<pair<int, int>>> adj(n + 1); // n+1 because nodes are 1-indexed
        for (auto& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }
        
        vector<int> dist(n+1, 1e9);
        dist[0]= 0; // 1 indexed array, so 0 will never be accessed
        dist[k]= 0;

        // Maintain a priority queue (min heap) with known distances
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});    // distance, node

        while(!pq.empty()){
            auto [dis, u]= pq.top();
            pq.pop();
            if(dis> dist[u]) continue;   // if distance is greater than previous min distance, discard
            // Syntax to access neighbors:
            for(auto& [v, weight] : adj[u]) { 
                if(dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        int delay= *max_element(dist.begin(), dist.end());

        return delay==1e9? -1: delay;
    }
};