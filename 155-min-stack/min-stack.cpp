class MinStack {
public:
	stack<int>s;
	int minElement = INT_MAX;//initalize with max value
	void push(int val) {
		if(minElement>=val){// whenever val is lesser than current minElement, store current minElement in stack and make val as current minElement
			s.push(minElement);
			 minElement = val;
		}
		  s.push(val);
	}
	void pop() {
		if(minElement==s.top()){//top is minElement then previous element will be previous minElement, so pop and store current top as current MinElement
			s.pop();
			minElement = s.top();
		}
		s.pop();
	}

    int top() {// return stack top
        return s.top();
    }

    int getMin() {//return minElement
        return minElement;
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