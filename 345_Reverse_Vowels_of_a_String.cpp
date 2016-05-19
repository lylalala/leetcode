class Solution {
public:
    bool isVowels(char a){
        if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||a=='A'||a=='E'||a=='I'||a=='O'||a=='U')
            return true;
        else
            return false;
    }
    string reverseVowels(string s) {
        if(s.length()==0)
            return s;
        int fi=0;
        int se=s.length()-1;
        while(fi<se){
            while(fi<se&&(!isVowels(s[fi])))
                fi++;
            while(fi<se&&(!isVowels(s[se])))
                se--;
            if(fi<se&&isVowels(s[fi])&&isVowels(s[se])){
                swap(s[fi],s[se]);
                fi++;
                se--;
            }
        }
        return s;
    }
};
