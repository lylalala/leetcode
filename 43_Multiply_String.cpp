class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")
            return "0";
        vector<int> n1(num1.length(),0);
        vector<int> n2(num2.length(),0);
        for(int i=0;i<num1.length();i++)
            n1[num1.length()-i-1]=num1[i]-'0';
        for(int i=0;i<num2.length();i++)
            n2[num2.length()-i-1]=num2[i]-'0';
        int carry=0;
        int temp;
        vector<int> res(num1.length()+num2.length(),0);
        for(int i=0;i<n1.size();i++){
            for(int j=0;j<n2.size();j++){
                temp=res[i+j]+carry+n1[i]*n2[j];
                res[i+j]=temp%10;
                carry=temp/10;
            }
            if(carry!=0){
                res[n2.size()+i]=carry;
                carry=0;
            }
        }
        if(res.back()==0)
            res.pop_back();
        string result(res.size(),'0');
        int pos=res.size()-1;
        for(int i=0;i<res.size();i++,pos--)
            result[i]=res[pos]+'0';
        return result;
    }
};
