class Solution {
public:
    string process(string temp){
        string res(temp.length()*2+1,'#');
        int j=1;
        for(int i=0;i<temp.length();i++){
            res[j]=temp[i];
            j+=2;
        }
        return res;
    }
    string shortestPalindrome(string s) {
        if(s=="")
            return "";
        string temp=process(s);
        int id=0;
        int right=0;
        vector<int> arr(temp.length(),1);
        int res=0;
        for(int i=0;i<temp.size();i++){
            if(i<right){
                arr[i]=min(arr[2*id-i],right-i+1);
            }
            while(i+arr[i]<temp.size()&&i-arr[i]>=0&&temp[i+arr[i]]==temp[i-arr[i]])
                arr[i]++;
            if(i+arr[i]>right){
                id=i;
                right=i+arr[i]-1;
            }
            if(i==arr[i]-1)
                res=arr[i]-1;
        }
        temp="";
        if((int)s.length()!=res){
            temp=s.substr(res,s.length()-res);
            reverse(temp.begin(),temp.end());
        }
        return temp+s;
    }
};
