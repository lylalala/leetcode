//开始没有考虑MIN值
class Solution {
public:
    double myPow(double x, int n) {
        bool isMin=false;
        int num=n;
        double temp=x;
        double res=1;
        if(num<0){
            if(num==-2147483648){
                num++;
                num=0-num;
                isMin=true;
            }
            else num=0-num;
            temp=1/temp;
        }
        while(num!=0){
            if(num&1) res*=temp;
            temp*=temp;
            num=num>>1;
        }
        if(isMin) res*=(1/x);
        return res;
    }
};
