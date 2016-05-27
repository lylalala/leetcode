class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m==n)
            return m;
        // if(m<=n/2)
        //     return 0;
        int tempm=m;
        int tempn=n;
        int pos=0;
        int i=0;
        while(tempm||tempn){
            if((tempm&1)!=(tempn&1))
                pos=i;
            i++;
            tempm=tempm>>1;
            tempn=tempn>>1;
        }
        return ((m&n)>>(pos+1))<<(pos+1);
    }
};
