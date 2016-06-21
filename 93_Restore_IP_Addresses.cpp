//0.01.1.1
class Solution {
private:
    vector<string> result;
    vector<string> res;
public:
    void help(string s,int pos,int depth){
        if(depth==4){
            string temp="";
            for(int i=0;i<res.size();i++)
                temp=temp+res[i]+".";
            temp=temp.substr(0,temp.length()-1);
            result.push_back(temp);
        }else if(depth==3){
            string temp=s.substr(pos,s.length()-pos);
            int tempNum=stoi(temp);
            if(((temp.length()>1&&temp[0]!='0')||(temp.length()==1))&&tempNum>=0&&tempNum<=255){
                res.push_back(temp);
                help(s,s.length(),depth+1);
                res.pop_back();
            }
        }else{
            for(int i=1;i<=3&&(pos+i)<s.length();i++){
                string temp=s.substr(pos,i);
                int tempNum=stoi(temp);
                if(((temp.length()>1&&temp[0]!='0')||(temp.length()==1))&&tempNum>=0&&tempNum<=255){
                    res.push_back(temp);
                    help(s,pos+i,depth+1);
                    res.pop_back();
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.length()>12||s.length()<4)
            return result;
        help(s,0,0);
        return result;
    }
};