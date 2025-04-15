class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> max_heap;
        for(int num: nums){
            max_heap.push(num);
        }
        for(int i=1; i<k; i++){
            max_heap.pop();
        }
        return max_heap.top();
    }
};