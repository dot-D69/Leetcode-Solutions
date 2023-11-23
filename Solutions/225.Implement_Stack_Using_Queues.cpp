//Using Two Queue
class MyStack {
public:
queue<int> que1;
queue<int> que2;
    MyStack() {
        
    }
    
    void push(int x) {
        que2.push(x);
        while(!que1.empty()){
            que2.push(que1.front());
            que1.pop();
        }
        swap(que1,que2);
    }
    
    int pop() {
        int res= que1.front();
        que1.pop();
        return res;
        
    }
    
    int top() {
        return que1.front();
    }
    
    bool empty() {
        return que1.empty();
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