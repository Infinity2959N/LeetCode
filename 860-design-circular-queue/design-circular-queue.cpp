class MyCircularQueue {
private:
    vector<int> queue;
    int front, rear, size;
public:
    MyCircularQueue(int k) {    //Initialize object with size of queue to be k
        queue.resize(k);
        front=rear=-1;
        size= k;
    }
    
    bool enQueue(int value) {   //return true if enqueue is successful
        // 3 cases: Full, empty and in middle
        if(isFull())    return false;
        if(isEmpty()){
            front++;
        }
        rear=(rear+1)%size;
        queue[rear]=value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())   return false;
        if(front==rear) front=rear=-1;
        else    front= (front+1)%size;
        return true;
    }
    
    int Front() {
        return front==-1 ? -1: queue[front];
    }
    
    int Rear() {
        return front==-1 ? -1: queue[rear];
    }
    
    bool isEmpty() {
        return front==-1;
    }
    
    bool isFull() {
        return front== (rear+1)%size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */