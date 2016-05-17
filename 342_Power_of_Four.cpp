class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<=0)
            return false;
        int temp=num;
        while(temp!=1){
            if((temp&3)!=0)
                return false;
            temp=temp>>2;
        }
        return true;
    }
};
