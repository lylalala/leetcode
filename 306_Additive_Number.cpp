class Solution {
public:
    string stradd(string& a,string& b){
        if(a.length()<b.length())
            return stradd(b,a);
        string res(a.length(),'0');
        int carry=0;
        int temp=0;
        int i=a.length()-1;
        int j=b.length()-1;
        for(;j>=0;i--,j--){
            temp=(a[i]-'0')+(b[j]-'0')+carry;
            carry=temp/10;
            temp=temp%10;
            res[i]=temp+'0';
        }
        for(;i>=0;i--){
            temp=(a[i]-'0')+carry;
            carry=temp/10;
            temp=temp%10;
            res[i]=temp+'0';
        }
        if(carry>0)
            return "1"+res;
        else
            return res;
    }
    bool solve(string& num1,string& num2,string num){
        int maxLen=max(num1.length(),num2.length());
        string res=stradd(num1,num2);
        string num3=num.substr(0,maxLen);
        if(maxLen>1&&num3[0]=='0')
            return false;
        if(res==num3&&(num3==num||solve(num2,num3,num.substr(maxLen))))
            return true;
        num3=num.substr(0,maxLen+1);
        if(res==num3&&(num3==num||solve(num2,num3,num.substr(maxLen+1))))
            return true;
        return false;
    }
    bool isAdditiveNumber(string num) {
        int len=num.length();
        for(int len1=1;len1<=len/2;len1++){
            string num1=num.substr(0,len1);
            if(len1>1&&num1[0]=='0')
                continue;
            for(int len2=1;len2<=len/2;len2++){
                string num2=num.substr(len1,len2);
                if(len2>1&&num2[0]=='0')
                    continue;
                if(solve(num1,num2,num.substr(len1+len2)))
                    return true;
            }
        }
        return false;
    }
};
