// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long b=1,e=n;
        long mid;
        while(b<=e){
            mid=(b+e)/2;
            if(isBadVersion(mid))
                e=mid-1;
            else
                b=mid+1;
        }
        return b;
    }
};
