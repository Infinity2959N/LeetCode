class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       // Hint: Heap: Maintain a max_heap that sorts based on frequency and then return the top k.
       // Hint (alternative): Bucket sort.

        // Heap Approach: Store all in a hashmap where value is the frequency
        // Store it in a min heap (based on freq) of size k
        unordered_map<int,int> map;
        for(auto i : nums){
            map[i]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans;

        for(auto it: map){
            pq.push({it.second, it.first});
            if(pq.size()>k)
                pq.pop();
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};