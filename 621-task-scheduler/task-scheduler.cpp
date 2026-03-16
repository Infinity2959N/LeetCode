class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Structure:  MaxHeap, Algo: Greedy, Pattern: Bottleneck/Frequency
        // Approach: Since we have a cooling period of n, we don't just pop most frequent and push it back, we have to make it "unavailable" for n units of time
        priority_queue<int> heap;   // To store just the frequencies. As we don't need the name of the process
        // Calculating the frequency
        int chars[26]={0};
        for(auto task: tasks){
            chars[task-'A']++;
        }
        // Fill the heap based on frequency
        for(int i=0; i<26; i++){
            if(chars[i]>0){
                heap.push(chars[i]);
            }
        }

        queue<pair<int, int>> waitQueue;   // Wait queue to store processed process for n time, push back to heap once time is up
        int time=0;
        
        while(!heap.empty() || !waitQueue.empty()){
            time++;
            if(!heap.empty()){
                int remaining= heap.top()-1;    // Calculates the remaining time out of the process with highest frequency. Heap just contains frequencies, not the processes themselves.
                heap.pop();
                if(remaining>0){
                    waitQueue.push({remaining, time+n});
                }
            }
            // Check if any task in waitQueue is ready to be pushed back
            if(!waitQueue.empty() && waitQueue.front().second==time){
                heap.push(waitQueue.front().first);
                waitQueue.pop();
            }
        }
        return time;

    }
};