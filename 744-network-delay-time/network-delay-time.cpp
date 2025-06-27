class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Build the adjList
        vector<vector<pair<int, int>>> graph(n+1);  // n+1 because in this problem, numbering is 1 based
        for(auto& edge: times){
            int u= edge[0], v=edge[1], time= edge[2];
            graph[u].push_back({v, time});
        }
        //Build the minHeap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;  // Format: (time, node)
        pq.push({0, k});    

        // Build distance array
        vector<int> dist(n+1, INT_MAX);
        dist[k]=0;

        // Build visited array: optimization
        vector<bool> visited(n + 1, false);

        // Standard Dijkstra
        while(!pq.empty()){
            auto [time, node]= pq.top();
            pq.pop();

            if (visited[node]) continue;
            visited[node] = true;

            for(auto&[neighbor, weight]: graph[node]){
                if(dist[neighbor]> time+weight){
                    dist[neighbor]= time+weight;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }

        // Find the max time: Question says minimum time, but minimum time for all nodes to recieve the signal would be the longest time taken for signal to reach from k node to any other node
        int maxTime= 0;
        for(int i=1; i<=n; i++){
            if(dist[i]== INT_MAX)   return -1;
            maxTime= max(maxTime, dist[i]);
        }
        return maxTime;
    }
};