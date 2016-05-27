long str2int(string str){
    bool flag=false;
    if(str[0]=='-'){
        flag=true;
        str=str.substr(1,str.length()-1);
    }
    long res=0;
    for(int i=0;i<str.length();i++){
        res=res*10+(str[i]-'0');
    }
    if(flag)
        res=0-res;
    return res;
}
class Solution {
public:
    int calculate(string s) {
        if(s=="")
            return 0;
        //-:-1 +:-2 (:-3
        stack<int> myStack;
        int i=0;
        while(i<s.length()){
            while(i<s.length()&&s[i]==' ')
                i++;
            if(i<s.length()){
                if(s[i]=='+'||s[i]=='-'){
                    myStack.push(((s[i]=='+')?-2:-1));
                    i++;
                }else if(s[i]=='('){
                    myStack.push(-3);
                    i++;
                }else if(s[i]==')'){
                    int num=myStack.top();
                    myStack.pop();
                    myStack.pop();
                    if((!myStack.empty())&&(myStack.top()==-1||myStack.top()==-2)){
                        int way=myStack.top();
                        myStack.pop();
                        int num2=myStack.top();
                        myStack.pop();
                        myStack.push(((way==-1)?num2-num:num+num2));
                    }else
                        myStack.push(num);
                    i++;
                }else{
                    int pos=i;
                    while(pos<s.length()&&s[pos]>='0'&&s[pos]<='9')
                        pos++;
                    int num=str2int(s.substr(i,pos-i));
                    if((!myStack.empty())&&(myStack.top()==-1||myStack.top()==-2)){
                        int way=myStack.top();
                        myStack.pop();
                        int num2=myStack.top();
                        myStack.pop();
                        myStack.push(((way==-1)?num2-num:num+num2));
                    }else
                        myStack.push(num);
                    i=pos;
                }
            }
        }
        return myStack.top();
    }
};
