class Solution {
public:
    int mypow(int num,int powNum){
        if(num==0)
            return 0;
        int res=1;
        int temp=num;
        while(powNum!=0){
            if(powNum&1){
                res=res*temp;
            }
            temp*=temp;
            powNum=powNum>>1;
        }
        return res;
    }
    int integerBreak(int n) {
        int res=0;
        int resTemp=0;
        int first,firstNum,second,secondNum;
        for(int i=2;i<=n;i++){
            first=n/i;
            secondNum=n%i;
            second=first+1;
            firstNum=i-secondNum;
            resTemp=mypow(first,firstNum)*mypow(second,secondNum);
            res=max(res,resTemp);
        }
        return res;
    }
};
