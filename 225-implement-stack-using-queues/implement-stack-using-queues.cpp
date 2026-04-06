

class MyStack {
public:
    queue<int> q;   // FIX: class member

    MyStack() {
    }
    
    void push(int x) {
        int s = q.size();
        q.push(x);

        // Rotate old elements behind new one
        for(int i = 0; i < s; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int n = q.front();
        q.pop();
        return n;
    }
    
    int top() {
        return q.front();   // FIX
    }
    
    bool empty() {
        return q.empty();
    }
};