vector<uint32_t> arr(32,0);
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i=0;
        uint32_t res=0;
        while(n){
            if(n&1){
                if(arr[i]==0)
                    arr[i]=1<<(31-i);
                res=res+arr[i];
            }
            i++;
            n=n>>1;
        }
        return res;
    }
};
