class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        int n= nums1.size();
        // for each node, you go right (i+1, j) or down(i, j+1)
        // Trick to save from repeating pairs: Push initial pairs into the pq
        for(int i=0; i< min(n, k); i++){
            pq.push({nums1[i]+nums2[0], i, 0});
        }
        vector<vector<int>> res;
        // Iterate k times, pop k smallest pairs from the pq
        while(k-- && !pq.empty()){
            auto [sum, i, j]= pq.top();pq.pop();
            res.push_back({nums1[i], nums2[j]});
            if(j+1< nums2.size()){
                pq.push({nums1[i]+nums2[++j], i, j});
            }
        }
        return res;
    }
};