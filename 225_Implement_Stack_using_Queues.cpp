class Stack {
private:
    queue<int> q1;
    queue<int> q2;
    int which;
public:
    Stack(){
        which=1;
    }
    // Push element x onto stack.
    void push(int x) {
        if(which==1){
            q1.push(x);
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }else{
            q2.push(x);
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
        }
        which=which^1;
    }

    // Removes the element on top of the stack.
    void pop() {
        if(which==1){
            q2.pop();
        }else{
            q1.pop();
        }
    }

    // Get the top element.
    int top() {
        if(which==1){
            return q2.front();
        }else{
            return q1.front();
        }
    }

    // Return whether the stack is empty.
    bool empty() {
        if(which==1){
            return q2.empty();
        }else{
            return q1.empty();
        }
    }
};
