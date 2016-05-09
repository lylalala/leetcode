string int2str(long num){
    if(num==0)
        return "0";
    if(num<0)
        return "-"+int2str(0-num);
    string res="";
    while(num!=0){
        string temp="0";
        temp[0]=(num%10)+'0';
        num=num/10;
        res=temp+res;
    }
    return res;
}
class Solution {
public:
    string solve(long numerator,long denominator){
        if(numerator<0&&denominator>0)
            return "-"+solve(0-numerator,denominator);
        else if(numerator>0&&denominator<0)
            return "-"+solve(numerator,0-denominator);
        else if(numerator<0&&denominator<0)
            return solve(0-numerator,0-denominator);
        long shishu=numerator/denominator;
        string res=int2str(shishu);
        long s=(numerator%denominator)*10;
        if(s==0)
            return res;
        else
            res+=".";
        vector<long> arr;
        vector<long> r;
        while(s!=0&&find(arr.begin(),arr.end(),s)==arr.end()){
            arr.push_back(s);
            r.push_back(s/denominator);
            s=(s%denominator)*10;
        }
        if(s==0){
            for(int i=0;i<r.size();i++){
                res=res+int2str(r[i]);
            }
        }else{
            long pos=0;
            for(;pos<arr.size();pos++){
                if(s==arr[pos]) break;
            }
            for(int i=0;i<r.size();i++){
                if(i==pos){
                    res=res+"(";
                }
                res=res+int2str(r[i]);
            }
            res=res+")";
        }
        return res;
    }
    string fractionToDecimal(int numerator, int denominator) {
        return solve(numerator,denominator);
    }
};
