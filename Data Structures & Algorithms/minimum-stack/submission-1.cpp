class MinStack {
public:
    stack<int> s;
    vector<int> prefix_on_size;

    MinStack() {
        prefix_on_size.push_back(INT_MAX);
    }
    
    void push(int val) {
        s.push(val);
        prefix_on_size.push_back(val);
        prefix_on_size[s.size()] = min(prefix_on_size[s.size() - 1], val);    
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return prefix_on_size[s.size()];
    }
};
