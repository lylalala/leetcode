class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1,0);
        int len=1;
        for(int i=1;i<res.size();i++){
            res[i]=__builtin_popcount(i);
        }
        return res;
    }
};
// class Solution {
// public:
//     int solve(int num){
//         int res=0;
//         while(num!=0){
//             num=num&(num-1);
//             res++;
//         }
//         return res;
//     }
//     vector<int> countBits(int num) {
//         vector<int> res(num+1,0);
//         for(int i=1;i<res.size();i++){
//             res[i]=solve(i);
//         }
//         return res;
//     }
// };
// class Solution {
// public:
//     vector<int> countBits(int num) {
//         vector<int> res(num+1,0);
//         int len=1;
//         for(int i=1;i<res.size();i++){
//             res[i]=res[i-len]+1;
//             if((i+1)/2==len)
//                 len*=2;
//         }
//         return res;
//     }
// };
