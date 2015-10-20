//设计思路：
/*
 将原来数据分解成若干二进制数据的加法，然后用分配率
 */

typedef vector<int> Array;
class Solution {
private:
    string addone(string num){
        int carry=0;
        string res(num.length(),'0');
        int thisnum=(num[num.length()-1]-'0'+carry)+1;
        if(thisnum>9){
            carry=1;
            res[num.length()-1]=(thisnum-10)+'0';
        }else{
            carry=0;
            res[num.length()-1]=thisnum+'0';
        }
        for(int i=num.length()-2;i>=0;i--){
            thisnum=num[i]-'0'+carry;
            if(thisnum>9){
                carry=1;
                res[i]=(thisnum-10)+'0';
            }else{
                carry=0;
                res[i]=thisnum+'0';
            }
        }
        return (carry==1)?"1"+res:res;
    }
    
    string multipyBy2(string num){
        int carry=0;
        string res(num.length(),'0');
        for(int i=num.length()-1;i>=0;i--){
            int thisnum=(num[i]-'0')*2+carry;
            if(thisnum>9){
                carry=1;
                res[i]=(thisnum-10)+'0';
            }else{
                carry=0;
                res[i]=thisnum+'0';
            }
        }
        return (carry==1)?"1"+res:res;
    }
    
    string divideBy2(string num){
        if(num.length()==1){
            string res(1,'0');
            res[0]=(int(num[0]-'0')/2)+'0';
            return res;
        }else if(num[0]=='1'){
            string res(num.length()-1,'0');
            int carry=1;
            for(int i=1;i<num.length();i++){
                int thisnum=(num[i]-'0')+carry*10;
                res[i-1]=(thisnum/2)+'0';
                carry=thisnum%2;
            }
            return res;
        }else{
            string res(num.length(),'0');
            int carry=0;
            for(int i=0;i<num.length();i++){
                int thisnum=(num[i]-'0')+carry*10;
                res[i]=(thisnum/2)+'0';
                carry=thisnum%2;
            }
            return res;
        }
    }
    
    Array decimal2binary(string num){
        Array restemp;
        string tempnum=num;
        while(tempnum!="0"){
            restemp.push_back((tempnum[tempnum.length()-1]-'0')%2);
            tempnum=divideBy2(tempnum);
        }
        Array res;
        for(int i=0;i<restemp.size();i++){
            if(restemp[i]==1)
                res.push_back(i);
        }
        return res;
    }
    
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")
            return "0";
        if(num1=="1")
            return num2;
        if(num2=="1")
            return num1;
        Array nums1Binary(decimal2binary(num1));
        Array nums2Binary(decimal2binary(num2));
        Array nums3Binary;
        for(int i=0;i<nums1Binary.size();i++){
            for(int j=0;j<nums2Binary.size();j++)
                nums3Binary.push_back(nums1Binary[i]+nums2Binary[j]);
        }
        sort(nums3Binary.begin(),nums3Binary.end(),less_equal<int>());
        int count=0;
        int start=0;
        int end=0;
        for(int i=0;i<nums3Binary.size();){
            count=1;
            start=i;
            while(i+1<nums3Binary.size()&&(nums3Binary[i+1]==nums3Binary[i]||nums3Binary[i+1]==0)){//记录重复单元有几个
                count=(nums3Binary[i+1]==0)?count:count+1;
                i++;
            }
            if(count>1){
                int small=count%2;//记录不变的数字有几个
                int big=count/2;//记录新生成的数字有几个
                int j=0;
                for(;j<big;j++)//从后往前放置新数字
                    nums3Binary[i-j]=nums3Binary[start]+1;
                if(small==1){//如果有不变的数字就放置
                    nums3Binary[i-j]=nums3Binary[start];
                    j++;
                }
                for(;i-j>=start;j++)//其余空位置为0
                    nums3Binary[i-j]=0;
                i=i-big+1;
            }else
                i++;
        }
        Array nums3BinNew;
        for(int i=0;i<nums3Binary.size();i++)
            if(nums3Binary[i]!=0)
                nums3BinNew.push_back(nums3Binary[i]);
        string result="1";
        for(int i=nums3BinNew.size()-1;i>=1;i--){
            int time=nums3BinNew[i]-nums3BinNew[i-1];
            for(int j=0;j<time;j++)
                result=multipyBy2(result);
            result=addone(result);
        }
        for(int i=0;i<nums3BinNew[0];i++)
            result=multipyBy2(result);
        return result;
    }
};
