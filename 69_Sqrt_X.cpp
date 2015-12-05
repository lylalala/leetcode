class Solution {
public:
    int mySqrt(int x) {
        int left,right;
        left=0;
        right=46340;
        int mid;
        long long int num;
        while(left<=right){
            mid=(left+right)/2;
            num=mid*mid;
            if(num==x)
                return mid;
            if(num<x)
                left=mid+1;
            else
                right=mid-1;
        }
        if(left>46340) left--;
        num=left*left;
        if(num>x)
            left--;
        return left;
    }
    
};
