class Solution {
public:
    map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    vector<string> result;

    void dfs(string airport){
        auto& destinations= adj[airport];
        while(!destinations.empty()){
            string next= destinations.top();
            destinations.pop();
            dfs(next);
        }
        result.push_back(airport);
    } 

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Eularian path problem
        
        // Ensuring lexicographical order: When building the adjacency list, use a map of multiset or a map of priority queue to always pick the alphabetically first one
        // Hierholzer's logic: Sttart a postorder DFS starting from JFK
        // Keep moving to the smallest available neighbor, deleting the edge as you go so you don't reuse tickets
        // When you hit a dead end, only then you add that city to the result
        // Reverse the result at the end
        // Why this works: The cities that are "dead ends" are actually the ones that should appear last in your itinerary. By adding them only when you can't go further, you naturally handle the "loops" in the graph.

        // use multiset instead of set because we can have duplicate tickets between two cities
        for(auto& t: tickets) adj[t[0]].push(t[1]);
        dfs("JFK");

        reverse(result.begin(), result.end());
        return result;
    }
};