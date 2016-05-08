class Solution {
public:
    void swap(string& str,int pos1,int pos2){
        int len=pos2-pos1;
        string temp=str.substr(pos1,len);
        for(int i=pos1-2;i>=0;i--){
            str[i+len+1]=str[i];
        }
        int i=0;
        for(;i<len;i++){
            str[i]=temp[i];
        }
        str[i]=' ';
    }
    void reverseWords(string &s) {
        bool tail=false;
        if(s[s.length()-1]==' ')
            tail=true;
        int p=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                s[i-p]=s[i];
                while(i<s.length()&&s[i]==' '){
                    i++;
                    p++;
                }
                p--;
            }
            s[i-p]=s[i];
        }
        s=s.substr(0,s.length()-p);
        if(s[0]==' ')
            s=s.substr(1,s.length()-1);
        if(tail)
            s=s.substr(0,s.length()-1);
        int fi,se;
        fi=se=0;
        int i=0;
        for(;i<s.length();i++){
            if(s[i]==' '){
                i++;
                fi=i;
                break;
            }
        }
        for(;i<=s.length();i++){
            if(s[i]==' '||i==s.length()){
                se=i;
                swap(s,fi,se);
                i++;
                fi=i;
            }
        }
    }
};
