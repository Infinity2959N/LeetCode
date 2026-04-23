class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        // min hops-> BFS
        // We make graph using the given route and find the shortest path between the nodes
        // To reduce complexity, we can sort each route and treat each route as a single node
        // How the statement makes sense: We are using the bus themselves as nodes, not stops

        // We need 2 mapping: Stops-> list of buses and BFS queue to store bus index

        // Process: Find all buses that pass through the source stop and push them
        // For each bus explore all stops it makes
        // For each of those stops find all other unvisited buses you can take
        // If any stop on the current bus is target, return the number of buses taken

        // Read notes for pattern recognition tips

        if(source==target) return 0;
        unordered_map<int, vector<int>> stopToBuses;

        for(int i=0; i<routes.size(); i++){
            for(auto stop: routes[i]){
                stopToBuses[stop].push_back(i); // i is the bus index
            }
        }
        vector<bool> visited(routes.size(), false);
        queue<int> busIdx;
        for(auto idx: stopToBuses[source]) busIdx.push(idx);
        int buses= 0;
        while(!busIdx.empty()){
            int s= busIdx.size();
            for(int i=0; i<s; i++){
                int idx= busIdx.front(); busIdx.pop();
                if(visited[idx]) continue;
                visited[idx]= true;
                for(int stop: routes[idx]){
                    if(stop==target) return buses+1;
                    for(int index: stopToBuses[stop]){
                        if(!visited[index]){
                            busIdx.push(index);
                        }
                    }
                }
            }
            buses++;
        }
        return -1;
    }
};