#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
int n,m,q;
int dp[2][1025];
int cn[1025]={0, 1, 1};
const int b[11]={1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
int main(){
    cin>>n>>m>>q;
    memset(dp, 0, sizeof(dp));
    int size=1<<m;
    cn[1]=1;cn[2]=1;
    for (int i=3; i<b[10]; ++i)
        cn[i] =cn[i>>1] +cn[i&1];
    vector<int> w(n+1,0);
    for(int i=1;i<=n;i++)
        cin>>w[i];
    int tmp = 1<<m;     //上限
    for(int i=1; i<=n; i++)
        for(int j=0; j<tmp; j++)
            if( cn[j]<=q )      //前m个位置选择清理的位置数量小于等于q。
                dp[i&1][j]=max( dp[~i&1][j>>1], dp[~i&1][(j>>1)+b[m-1]] ) + (j&1)*w[i]; //i的决策由j的最后一位表示。
    //最大垃圾量可能存在于任何排列中，所以要全扫一遍才知道。
    int ans=0;
    for(int i=1; i<tmp; i++)
        ans=max(ans, dp[n&1][i]);
    cout<<ans<<endl;
    return 0;
}
