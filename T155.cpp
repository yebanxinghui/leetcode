class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) 
    {
        if(x <= minnum)
        {
            s.push(minnum);
            minnum = x;
        }
        s.push(x);
    }
    
    void pop() 
    {
        if(!s.empty() && s.top() == minnum)
        {
            s.pop();
            minnum = s.top();
        }
        s.pop();
        
    }
    
    int top() 
    {
        if(!s.empty()) return s.top();
        return NULL;
    }
    
    int getMin() 
    {
        return minnum;
    }
private:
    stack<int> s;
    int minnum = INT_MAX;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */