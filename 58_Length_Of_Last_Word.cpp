//although it's a easy problem, i make two mistakes.   ==。
//触发器的使用
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.length()==0)
            return 0;
        int res=0;
        bool open=false;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==' '){
                if(open)
                    break;
            }
            else{//只有开始读入字符后才打开终止开关 
                res++;
                open=true;
            }
        }
        return res;
    }
};
