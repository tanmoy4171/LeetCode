class MyCircularDeque {
public:
    int *v;
    int cap, size;
    int front;
    MyCircularDeque(int k) {
        cap = k;
        size = 0 ;
        v = new int[cap];
        front = 0;
    }
    
    bool insertFront(int value) {
        if(size == cap)
            return false;
        front = (front -1 +cap)%cap;
        v[front] = value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
       if(size == cap)
            return false;
        int rear = (front + size)%cap ;
        v[rear] = value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(size == 0)
            return false;
        size--;
        front = (front+1)%cap;
        return true;
    }
    
    bool deleteLast() {
        if(size == 0)
            return false;
        size--;
        return true;
    }
    
    int getFront() {
        if(size == 0)
            return -1;
        return v[front];
    }
    
    int getRear() {
        if(size == 0)
            return -1;
        return v[(front + size -1) % cap];
    }
    
    bool isEmpty() {
        return (size == 0);
    }
    
    bool isFull() {
        return (size == cap);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */