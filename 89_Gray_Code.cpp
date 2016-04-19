class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        int len=1;
        res.push_back(0);
        for(int i=1;i<=n;i++){
            for(int j=len-1;j>=0;j--)
                res.push_back(res[j]+len);
            len=len*2;
        }
        return res;
    }
};
