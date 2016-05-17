#include<iostream>
#include<vector>
using namespace std;
int n,m;
int main(){
    cin>>n>>m;
    vector<int> need(n,0);
    vector<int> value(n,0);
    for(int i=0;i<n;i++)
        cin>>need[i]>>value[i];
    vector<int> dp(m+1,0);
    for(int i=0;i<n;i++){
        for(int j=m;j>need[i];j--){
            dp[j]=max(dp[j],dp[j-need[i]]+value[i]);
        }
    }
    cout<<dp.back()<<endl;
    return 0;
}
