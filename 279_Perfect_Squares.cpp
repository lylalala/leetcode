class Solution {
public:
    int findLog(int n) {
        int left=1,right=n+1;
        while(left<right){
            int mid=(left+right)/2;
            if(mid*mid<=n){
                left=mid+1;
            }else{
                right=mid;
            }
        }
        return left-1;
    }
    int numSquares(int n) {
        int res=1;
        vector<int> num(findLog(n)+1,0);
        for(int i=0;i<num.size();i++){
            num[i]=i*i;
        }
        queue<int> q;
        for(int i=num.size()-1;i>0;i--){
            if(n==num[i]) return res;
            q.push(n-num[i]);
        }
        q.push(-1);
        while(q.front()!=-1){
            res++;
            while(q.front()!=-1){
                int tempNum=q.front();
                q.pop();
                int tempIndex=findLog(tempNum);
                for(int i=tempIndex;i>0;i--){
                    if(tempNum==num[i]) return res;
                    q.push(tempNum-num[i]);
                }
            }
            q.pop();
            q.push(-1);
        }
        return -1;
    }
};
