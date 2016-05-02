class Solution {
public:
    int str2int(string str){
        bool flag=false;
        if(str[0]=='-'){
            flag=true;
            str=str.substr(1,str.length()-1);
        }
        int res=0;
        for(int i=0;i<str.length();i++){
            res=res*10+(str[i]-'0');
        }
        if(flag)
            res=0-res;
        return res;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> q;
        // int res;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                int temp2=q.top();
                q.pop();
                int temp1=q.top();
                q.pop();
                if(tokens[i]=="+")
                    q.push(temp1+temp2);
                if(tokens[i]=="-")
                    q.push(temp1-temp2);
                if(tokens[i]=="*")
                    q.push(temp1*temp2);
                if(tokens[i]=="/")
                    q.push(temp1/temp2);
            }else{
                q.push(str2int(tokens[i]));
            }
        }
        return q.top();
    }
};
