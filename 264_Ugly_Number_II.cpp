class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> arr(n,1);
        int i2=0,i3=0,i5=0;
        int n2,n3,n5;
        for(int i=1;i<arr.size();i++){
            n2=arr[i2]*2;
            n3=arr[i3]*3;
            n5=arr[i5]*5;
            int minnum=min(min(n2,n3),n5);
            if(n2==minnum){
                arr[i]=n2;
                i2++;
            }
            if(n3==minnum){
                arr[i]=n3;
                i3++;
            }
            if(n5==minnum){
                arr[i]=n5;
                i5++;
            }
        }
        return arr.back();
    }
};
