//use a mathematic approach
//for example:
/*
n=4,k=17
position of array 0  1  2  3  
num               1  2  3  4
numSum            24 6  2
pos               2  2  0  0 : which=17-1=16  16/6=2  (16-6*2)/2=2
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char> num(n,'1');
        for(int i=0;i<n;i++)
            num[i]+=i;
        
        vector<int> numSum(n,1);
        for(int i=numSum.size()-2;i>=0;i--)
            numSum[i]=numSum[i+1]*(numSum.size()-i);
            
        vector<int> pos(n,0);
        int which=k-1;
        for(int i=0;i<n-1;i++){
            pos[i]=which/numSum[i+1];
            which-=pos[i]*numSum[i+1];
            if(which==0) break;
        }
        
        vector<char> res;
        for(int i=0;i<n;i++){
            res.push_back(num[pos[i]]);
            num.erase(num.begin()+pos[i]);
        }
        
        string resString;
        resString.assign(res.begin(),res.end());
        return resString;
    }
};
