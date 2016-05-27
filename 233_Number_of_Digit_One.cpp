class Solution {
public:
    int countDigitOne(int n) {
        if(n<=0)
            return 0;
        int a[]={0,1,20,300,4000,50000,600000,7000000,80000000,900000000};
        int b[]={0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
        string num=to_string(n);
        int res=0;
        int len=num.length();
        for(int i=0;i<len;i++){
            if(num[i]>'1')
                res=res+b[len-i]+(num[i]-'0')*a[len-i-1];
            else if(num[i]=='1'){
                // string temp=num.substr(i+1,len-i-1);
                res=res+a[len-i-1]+(n%b[len-i]+1);
            }
        }
        return res;
    }
};
