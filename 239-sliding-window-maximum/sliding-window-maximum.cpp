class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // To find the max element in the window currently
        // Instead of recomputation, think of candidate management
        // A member is a candidate for max only if it is currently inside the window and no one to it's right is bigger than it

        // Club bouncer logic: Implement a deque (monotonic) that stores indices
        // When a new element arrives: Before it enters ,it looks at elements in the back, if they are smaller than it, it throws them out
        // Window slides: Check if the element that left just now was in front of the deque, pop if true
        // The element at the front will be the new element

        deque<int> dq;
        vector<int> result;

        for(int i=0; i<nums.size(); i++){
            // The bouncer
            while(!dq.empty() && nums[i]>= nums[dq.back()]){
                dq.pop_back();
            }dq.push_back(i);

            // The cleaner
            if(dq.front()== i-k){
                dq.pop_front();
            }
            if(i>=k-1) result.push_back(nums[dq.front()]);
        }
        return result;
    }
};