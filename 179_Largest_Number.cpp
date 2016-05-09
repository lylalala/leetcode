int str2int(string str){
    bool flag=false;
    if(str[0]=='-'){
        flag=true;
        str=str.substr(1,str.length()-1);
    }
    int res=0;
    for(int i=0;i<str.length();i++){
        res=res*10+(str[i]-'0');
    }
    if(flag)
        res=0-res;
    return res;
}

string int2str(int num){
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
bool comp(string a,string b){
    return (a+b)>(b+a);
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for(int i=0;i<nums.size();i++){
            arr.push_back(int2str(nums[i]));
        }
        sort(arr.begin(),arr.end(),comp);
        string res="";
        for(int i=0;i<nums.size();i++)
            res=res+arr[i];
        int i=0;
        while(res[i]=='0')
            i++;
        if(i==res.length())
            return "0";
        else
            return res.substr(i,res.length()-i);
    }
};
