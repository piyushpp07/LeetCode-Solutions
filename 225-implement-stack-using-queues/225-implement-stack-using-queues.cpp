class MyStack {
private:
        deque<int>que;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        que.push_back(x);
    }
    
    int pop() {
            int n = que.back();
            que.pop_back();
            return n;
    }
    
    int top() {
        return que.back();
    }
    
    bool empty() {
        if(que.size()==0)
                return true;
            return false;
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