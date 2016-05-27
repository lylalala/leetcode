class Solution {
public:
    int findnext(string str){
        vector<int> next(str.length(),0);
        next[0]=0;
        int k=0;
        for(int i=1;i<str.length();i++){
            while(k>0&&str[k]!=str[i])
                k=next[k-1];
            if(str[k]==str[i])
                k++;
            next[i]=k;
        }
        return next.back();
    }
    string shortestPalindrome(string s) {
        if(s=="")
            return "";
        string s2=s;
        reverse(s2.begin(),s2.end());
        string temp=s+"*"+s2;
        int len=findnext(temp);
        temp="";
        temp=s.substr(len,s.length()-len);
        reverse(temp.begin(),temp.end());
        return temp+s;
    }
};
