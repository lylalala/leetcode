class Solution {
public:
    bool isMatch(string s, string p) {
        if(s==""){
            if(p==""||(p.length()==1&&p[0]=='*'))
            return true;
            else
            return false;
        }
        if(s!=""&&p=="")
        return false;
        string pp=p;
        //版本三：没有考虑"?*?*?*"这种傻逼匹配方式
        /*for(int i=0;i<pp.length()-1;i++){
         if(pp[i]=='*'&&pp[i+1]=='?'){
         pp[i]='?';
         pp[i+1]='*';
         }
         }*/
        int x,w;
        for(int i=0;i<pp.length()-1;i++){
            if(pp[i]=='*'||pp[i]=='?'){
                x=w=0;
                for(int j=i;j<pp.length()&&(pp[j]=='*'||pp[j]=='?');j++){
                    if(pp[j]=='*')
                    x++;
                    else
                    w++;
                }
                int j=0;
                for(i=i;j<w;i++,j++)
                pp[i]='?';
                j=0;
                for(i=i;j<x;i++,j++)
                pp[i]='*';
            }
        }
        int lastN,lastM;
        lastN=lastM=-1;
        int n,m;
        n=m=0;
        while(1){
            if(pp[m]!='*'){
                if(pp[m]!='?'&&pp[m]!=s[n]){
                    //返回上一个*的位置
                    if(lastN==-1&&lastM==-1)
                    return false;
                    n=lastN;
                    m=lastM;
                }
                else{
                    n++;
                    m++;
                    if(n==s.length()&&m==pp.length())
                    return true;
                    if(m==pp.length()){
                        //返回上一个'*'的位置
                        if(lastN==-1&&lastM==-1)
                        return false;
                        n=lastN;
                        m=lastM;
                    }
                    if(n==s.length()){
                        //版本一：没有考虑s遍历结束后pp还存在一个'*'的情况
                        /*return fasle*/
                        
                        //版本二: 没有考虑s遍历结束后pp还存在多个个'*'的情况。。。==。我是傻逼吗
                        /*if(m==pp.length()-1&&pp[m]=='*')
                         return true;
                         else
                         return false;*/
                        
                        //版本三：
                        while(pp[m]=='*')
                        m++;
                        if(m==pp.length())
                        return true;
                        else
                        return false;
                    }
                }
            }
            else{
                while(m<pp.length()&&pp[m+1]=='*')
                m++;
                if(m==pp.length()-1)
                return true;
                //找出能够匹配m+1的字符
                int i;
                for(i=n;i<s.length();i++){
                    if(pp[m+1]==s[i]){
                        //记录当前位置
                        lastN=n+1;
                        lastM=m;
                        n=i;
                        m++;
                        break;
                    }
                }
                if(i==s.length())
                return false;
            }
        }
    }
};