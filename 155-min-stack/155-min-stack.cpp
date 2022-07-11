class MinStack
{
    private:
        stack<int> st, ss;
    public:
        MinStack() {}

    void push(int val)
    {
        if (st.size() == 0)
        {
            st.push(val);
            ss.push(val);
        }
        else
        {
            st.push(val);
            int p = getMin();
            if (p >= val)
                ss.push(val);
        }
    }

    void pop()
    {
        
        if (st.top() == ss.top())
        {
            st.pop();
            ss.pop();
        }
        else
            st.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return ss.top();
    }
};

/**
 *Your MinStack object will be instantiated and called as such:
 *MinStack* obj = new MinStack();
 *obj->push(val);
 *obj->pop();
 *int param_3 = obj->top();
 *int param_4 = obj->getMin();
 */