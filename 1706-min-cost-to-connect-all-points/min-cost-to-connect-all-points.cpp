class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n= points.size();
        vector<int> key(n, INT_MAX);
        vector<bool> inMST(n, false);
        key[0]= 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;    // {cost, node}
        pq.push({0, 0});

        int mstCost= 0;

        while(!pq.empty()){
            auto [cost, u]= pq.top();
            pq.pop();

            if(inMST[u])    continue;

            inMST[u]= true;
            mstCost+= cost;

            for(int v=0; v<n; v++){
                if(!inMST[v]){
                    int newCost= abs(points[u][0]- points[v][0])+ abs(points[u][1]- points[v][1]);
                    if(newCost< key[v]){
                        key[v]= newCost;
                        pq.push({key[v], v});
                    }
                }
            }
        }
        return mstCost;
    }
};