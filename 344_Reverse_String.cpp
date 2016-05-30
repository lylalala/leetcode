class Solution {
public:
    string reverseString(string s) {
        // stack<char> myStack;
        // for(int i=0;i<s.length();i++)
        //     myStack.push(s[i]);
        // for(int i=0;i<s.length();i++){
        //     s[i]=myStack.top();
        //     myStack.pop();
        // }
        // return s;
        int i=0;
        int j=s.length()-1;
        while(i<=j)
            swap(s[i++],s[j--]);
        return s;
    }
};
