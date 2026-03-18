// Last updated: 3/18/2026, 2:28:49 PM
class MyStack {
public:
    queue<int> q1,q2;

    void push(int x){
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    int pop(){
        int r = q1.front();
        q1.pop();
        return r;
    }
    int top() {
        if (q1.empty()) {
            throw runtime_error("Stack is empty");
        }
        return q1.front();
    }

    
    bool empty() {
        return q1.empty();
    }
   
};

