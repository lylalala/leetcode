class Solution {
    
public:
    int sort(vector<int>& arr,int fi,int se){
        int flag=arr[fi];
        int f,s;
        f=fi;s=se-1;
        while(f<s){
            while(f<s&&arr[s]>=flag)
                s--;
            arr[f]=arr[s];
            while(f<s&&arr[f]<flag)
                f++;
            arr[s]=arr[f];
        }
        arr[f]=flag;
        return f;
    }
    void wiggleSort(vector<int>& nums) {
        int need=(nums.size()-1)/2;
        int start=need+1;
        int a=0;
        int b=nums.size();
        while(1){
            int temp=sort(nums,a,b);
            if(temp==need)
                break;
            else if(temp>need){
                b=temp;
            }else{
                a=temp+1;
            }
        }
        
        int mid=nums[need];
// #define A(x) (x>=(nums.size()/2))?(x-nums.size()/2)*2:2*x+1
        int n = nums.size();
#define A(i) nums[(1+2*(i)) % (n|1)]
        int i,j,k;
        i=j=0;k=nums.size()-1;
        while(j<=k){
            if(mid<A(j)){
                swap(A(i++),A(j++));
            }else if(mid>A(j)){
                swap(A(j),A(k--));
            }else
                j++;
        }
    }
};
