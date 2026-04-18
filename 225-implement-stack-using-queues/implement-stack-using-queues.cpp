class MyStack {
public:
    /*
    Stack: LIFO (Last in First out)
    Queue: FIFO (First in First out)
    If inserted: 1,2,3,4,5; And you pop; Stack: 5, Queue: 1

    How to implement stack using queue:
    We need 1 queue. 
    Push: Add the element to the queue, now for n-1 times (where n is the size of queue) pop from back and push in front
    Efficiency: O(n) for push, O(1) for pop
    */
    queue<int> st;
    MyStack() {
    }
    
    void push(int x) {
        st.push(x);
        int n= st.size();

        for(int i=0; i<n-1; i++){
            int temp= st.front();
            st.pop();
            st.push(temp);
        }
    }
    
    int pop() {
        int x= st.front();
        st.pop();
        return x;
    }
    
    int top() {
       return st.front(); 
    }
    
    bool empty() {
       return st.empty(); 
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */