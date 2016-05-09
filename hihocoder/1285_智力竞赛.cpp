#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <stack>
using namespace std;
int const INF = 0x3fffffff;
int str2int(string str){
    bool flag=false;
    if(str[0]=='-'){
        flag=true;
        str=str.substr(1,str.length()-1);
    }
    int res=0;
    for(int i=0;i<str.length();i++){
        res=res*10+(str[i]-'0');
    }
    if(flag)
        res=0-res;
    return res;
}
int n,m,s,t;
int main()
{
    int Q;
    cin>>Q;
    while(Q--)
    {
        cin>>n>>m>>s>>t;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++)
            cin>>a[i];
        vector<vector<int> > dp(n+1,vector<int>(m+1,INF));
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int k=a[i]/s+(a[i]%s!=0);
                for(;k>=0;k--){
                    int res=a[i]-k*s;
                    int wrong=0;
                    if(res>0)
                        wrong=res/t+(res%t!=0);
                    if(j>=k+wrong&&dp[i-1][j-k-wrong]<INF)
                        dp[i][j]=min(dp[i][j],dp[i-1][j-k-wrong]+k);
                }
            }
        }
        int r=INF;
        for(int i=1;i<=m;i++)
            r=min(r,dp[n][i]);
        if(r == INF)
            printf("No\n");
        else
            printf("%d\n", r);
    }
    return 0;
}

