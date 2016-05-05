class Solution {
public:
    int bulbSwitch(int n) {
        int res=1;
        for(;res*res<=n;res++){}
        return res-1;
    }
};
