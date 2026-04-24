class MedianFinder {
/*
Maintain two heaps, one for min elements (maxheap) and one for max elements (minheap)
We need the sizes of both heaps to be similar(difference<=1)
If difference is greater,or the top of min elements (max min element) is greater than top of max elements (min max element), then we balance
If length is not equal, return the top of the bigger heap, else return top of both/2.0
*/

    priority_queue<int> minElements;    //max heap
    priority_queue<int, vector<int>, greater<int>> maxElements; // min heap
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        // This code removes most of the edge cases checks by ensuring either both are same height or minElements is greater by 1
        minElements.push(num);
        maxElements.push(minElements.top()); minElements.pop();
        if(maxElements.size()> minElements.size()){
            minElements.push(maxElements.top()); maxElements.pop();
        }
    }
    
    double findMedian() {
        if(minElements.size()> maxElements.size()) return minElements.top();
        else return (minElements.top()+ maxElements.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */