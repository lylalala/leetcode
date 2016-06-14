class Solution {
public:
    int calculate(string s) {
        int num=0;
        vector<int> lastnum;
        vector<int> op;
        for(int i=0;i<=s.length();i++){
            if(s[i]==' ')
                continue;
            else{
                if(i<s.length()&&isdigit(s[i])){
                    num=num*10+s[i]-'0';
                }else{
                    if(!op.empty()&&(op.back()==1||op.back()==-1)){
                        int temp=lastnum.back();
                        lastnum.pop_back();
                        if(op.back()==1)
                            lastnum.push_back(temp*num);
                        else
                            lastnum.push_back(temp/num);
                        op.pop_back();
                    }else if(op.empty()||op.back()==2||op.back()==-2){
                        lastnum.push_back(num);
                    }
                    if(i==s.length()){
                        if(op.empty())
                            break;
                        else{
                            if(op.back()==2){
                                lastnum.push_back(lastnum[0]+lastnum[1]);
                            }else{
                                lastnum.push_back(lastnum[0]-lastnum[1]);
                            }
                            lastnum.erase(lastnum.begin());
                            lastnum.erase(lastnum.begin());
                        }
                    }
                    if(s[i]=='*'){
                        op.push_back(1);
                    }else if(s[i]=='/'){
                        op.push_back(-1);
                    }else if(s[i]=='+'){
                        if(!op.empty()){
                            if(op.back()==2){
                                lastnum.push_back(lastnum[0]+lastnum[1]);
                            }else{
                                lastnum.push_back(lastnum[0]-lastnum[1]);
                            }
                            lastnum.erase(lastnum.begin());
                            lastnum.erase(lastnum.begin());
                            op.pop_back();
                        }
                        op.push_back(2);
                    }else if(s[i]=='-'){
                        if(!op.empty()){
                            if(op.back()==2){
                                lastnum.push_back(lastnum[0]+lastnum[1]);
                            }else{
                                lastnum.push_back(lastnum[0]-lastnum[1]);
                            }
                            lastnum.erase(lastnum.begin());
                            lastnum.erase(lastnum.begin());
                            op.pop_back();
                        }
                        op.push_back(-2);
                    }
                    num=0;
                }
            }
        }
        return lastnum.back();
    }
};
