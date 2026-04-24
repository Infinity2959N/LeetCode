class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // keep a max heap of size k. If full, check the top, if top larger than curr, pop and push
        priority_queue<tuple<int, int, int>> heap;

        int currLen=0;

        for(int i=0; i<points.size(); i++){
            int x= points[i][0], y= points[i][1];
            int dist= (pow(x, 2)+ pow(y, 2));   // comparing sqrt(x) with sqrt(y) and x with y give same results
            if(currLen==k){
                auto [maxDis, a, b]= heap.top();
                if(dist< maxDis){
                    heap.pop();
                    heap.push({dist, x, y});
                }
            }
            if(currLen<k){
                heap.push({dist, x, y});
                currLen++;
            }
        }
        vector<vector<int>> ans;
        while(!heap.empty()){
            auto [dis, x, y]= heap.top(); heap.pop();
            ans.push_back({x, y});
        }
        return ans;
    }
};