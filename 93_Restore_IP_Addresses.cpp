//"00000"
class Solution {
private:
    vector<string> result;
    string tempStr;
    int tempInt;
public:
    vector<string> restoreIpAddresses(string s) {
        string res="";
        dfs(s,0,res,1);
        return result;
    }
    int str2int(string str){
        if((str.length()==3&&str[0]=='0')||(str.length()==2&&str[0]=='0'))
            return -1;
        int res=0;
        for(int i=0;i<str.length();i++){
            res=res*10+(str[i]-'0');
        }
        return res;
    }
    void dfs(string& s,int pos1,string res,int depth){
        if(depth==4){
            tempStr=s.substr(pos1,s.length()-pos1);
            tempInt=str2int(tempStr);
            if(tempInt>=0&&tempInt<=255){
                res=res+tempStr;
                result.push_back(res);
                return;
            }
        }else{
            int maxLen,minLen,reserveLen,len;
            len=res.length();
            for(int i=1;i<=3;i++){
                maxLen=(4-depth)*3;
                minLen=(4-depth)*1;
                reserveLen=s.length()-pos1-i;
                if(reserveLen<minLen||reserveLen>maxLen)
                    continue;
                tempStr=s.substr(pos1,i);
                tempInt=str2int(tempStr);
                if(tempInt>=0&&tempInt<=255){
                    res=res+tempStr+".";
                }else
                    continue;
                dfs(s,pos1+i,res,depth+1);
                res=res.substr(0,len);
            }
        }
    }
};

