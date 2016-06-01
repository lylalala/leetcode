class Queue {
private:
    stack<int> s0;//push
    stack<int> s1;//pop
public:
    // Push element x to the back of queue.
    void push(int x) {
        while(!s1.empty()){
            s0.push(s1.top());
            s1.pop();
        }
        s0.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        while(!s0.empty()){
            s1.push(s0.top());
            s0.pop();
        }
        s1.pop();
    }

    // Get the front element.
    int peek(void) {
        while(!s0.empty()){
            s1.push(s0.top());
            s0.pop();
        }
        return s1.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s0.empty()&&s1.empty();
    }
};
