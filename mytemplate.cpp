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

int main()
{
    int Q;
    while(scanf("%d", &Q) != EOF)
    {
        //scanf("%d%d%d%d", &N, &M, &K, &T);
        //printf("%lld\n", ans);
    }
    return 0;
}
