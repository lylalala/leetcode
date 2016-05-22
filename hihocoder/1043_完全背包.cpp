#include<iostream>
#include<vector>
using namespace std;
int n,m;
int main(){
    cin>>n>>m;
    vector<int> need(n,0);
    vector<int> value(n,0);
    vector<int> dp(m,0);
    for(int i=0;i<n;i++)
        cin>>need[i]>>value[i];
    for(int i=0;i<n;i++){
        for(int j=need[i];j<m;j++){
            dp[j]=max(dp[j],dp[j-need[i]]+value[i]);
        }
    }
    cout<<dp.back()<<endl;
    return 0;
}
