//---------------------------------------------------------------------------------------------------------------
//43题 Multiply Strings
//20ms,21.29%
//按照手算原理，按位乘再累加
//刘阳，2015.10.10
//liuyang070424@163.com/liuyang070424@gmail.com
//---------------------------------------------------------------------------------------------------------------

class Solution {
public:
    string add(string numBig, string numSmall){
        int carry=0;
        string res(numBig.length(),'0');
        for(int i=numSmall.length()-1, j=numBig.length()-1;i>=0;i--,j--){
            int temp=(numBig[j]-'0')+(numSmall[i]-'0')+carry;
            res[j]=(temp%10)+'0';
            carry=(temp/10);
        }
        for(int i=numBig.length()-numSmall.length()-1;i>=0;i--){
            int temp=(numBig[i]-'0')+carry;
            res[i]=(temp%10)+'0';
            carry=(temp/10);
        }
        if(carry!=0)
            res=string(1,carry+'0')+res;
        return res;
    }
    string multiplyOne(string num, char numBit){
        int carry=0;
        string res(num.length(),'0');
        for(int i=num.length()-1;i>=0;i--){
            int temp=(num[i]-'0')*(numBit-'0')+carry;
            res[i]=(temp%10)+'0';
            carry=(temp/10);
        }
        if(carry!=0)
            res=string(1,carry+'0')+res;
        return res;
    }
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")
            return "0";
        string numa,numb;
        string result="0";
        vector<string> res;
        if(num1.length()>num2.length()){//把小的放在b里面，作乘数
            numa=num1;
            numb=num2;
        }else{
            numa=num2;
            numb=num1;
        }
        for(int i=numb.length()-1;i>=0;i--)
            res.push_back(multiplyOne(numa,numb[i])+string(numb.length()-i-1,'0'));//string(i,'0')中i是否可以等于0？
        result=res[res.size()-1];
        for(int i=res.size()-2;i>=0;i--){
            result=add(result,res[i]);
        }
        return result;
    }
};