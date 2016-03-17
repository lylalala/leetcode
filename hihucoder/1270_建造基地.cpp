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
#define CLR(a, b) memset(a, (b), sizeof(a))
#define fi first
#define se second
typedef long long LL;
using namespace std;
typedef pair<int, int> pii;
//const int MAXM = 1e3+10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
void getmax(int &a, int b) {a = max(a, b); }
void getmin(int &a, int b) {a = min(a, b); }
void add(LL &x, LL y) { x += y; x %= MOD; }
//pii data[110];
int a[110];
int b[110];
LL dp[10010];
int main()
{
    int Q;
    while(scanf("%d", &Q) != EOF)
    {
        while (Q--) {
            int N,M,K,T;
            scanf("%d%d%d%d", &N, &M, &K, &T);
            for(int i=1; i<=M; i++) scanf("%d", a+i);
            for(int i=1; i<=M; i++) scanf("%d", b+i);
            LL res=0;
            for (int floor=0; floor<N; floor++) {
                CLR(dp, INF);
                dp[0]=0;
                for (int i=1; i<=M; i++) {
                    for (int j=0; j<=K; j++) {
                        dp[min(j+b[i],K)]=min(dp[min(j+b[i],K)],dp[j]+a[i]);                 }
                }
                res+=dp[K];
                for(int v=1; v<=M; v++)
                    b[v] /= T;
            }
            if(res >= INF) puts("No Answer");
            else printf("%lld\n", res);
        }
    }
    return 0;
}

