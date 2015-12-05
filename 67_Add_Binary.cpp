//a easy problem
class Solution {
public:
    string addBinary(string a, string b) {
        string resTemp=string(max(a.length(),b.length())+1,'a');
        string aa=a;
        string bb=b;
        if(aa.length()<bb.length()) swap(aa,bb);
        int carry=0;
        int sum;
        int i,j,k;
        for(i=aa.length()-1,j=bb.length()-1,k=resTemp.length()-1;i>=0&&j>=0;i--,j--,k--){
            sum=(aa[i]-'0')+(bb[j]-'0')+carry;
            resTemp[k]=(sum==0||sum==2)?'0':'1';
            carry=(sum==0||sum==1)?0:1;
        }
        for(i=i,k=k;i>=0;i--,k--){
            sum=(aa[i]-'0')+carry;
            resTemp[k]=(sum==0||sum==2)?'0':'1';
            carry=(sum==0||sum==1)?0:1;
        }
        resTemp[0]=(carry==1)?'1':resTemp[0];
        if(resTemp[0]=='1')
            return resTemp;
        else{
            string res(resTemp.begin()+1,resTemp.end());
            return res;
        }
    }
};
