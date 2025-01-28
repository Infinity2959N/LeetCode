class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int num: nums){
            map[num]++;
        }
        
        //we have to return k elements that have the highest frequency
        // Step 2: Use a min-heap to store the top k elements
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    
    for (auto& entry : map) {
        minHeap.push({entry.second, entry.first});  // Insert frequency and element into heap
        
        // If the heap exceeds size k, remove the element with the smallest frequency
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    // Step 3: Extract the result from the heap
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);  // Push the element (not the frequency) to result
        minHeap.pop();
    }
    
    return result;
    }
};