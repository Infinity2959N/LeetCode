class MinStack {
public:
    vector<int> arr;
    vector<int>minStack;
    MinStack() {}
    
    void push(int val) {
        arr.push_back(val);
        if(minStack.empty() ||  minStack.back()>=val)   minStack.push_back(val);
    }
    
    void pop() {
        if(arr.back()==minStack.back()) minStack.pop_back();
        arr.pop_back();
    }
    
    int top() {
        return arr.back();
    }
    
    int getMin() {
        return minStack.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */