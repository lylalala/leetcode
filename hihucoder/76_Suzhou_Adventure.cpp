//not finish
#include<iostream>
#include<vector>
using namespace std;
int n,k,m;
int score[101];
int recom[6];
int road[100][2];
int roadPoint[100];
int Scores=0;
vector<int> hasVisit;
vector<int> isRoot;
bool isRecom(int num){
    for (int i=1; i<=k; i++) {
        if (recom[i]==num) {
            return true;
        }
    }
    return false;
}

bool dp(int root){
    bool res = false;
    if (isRecom(root)) {
        res=true;
    }
    vector<bool> tmpArr;
    for(int i=roadPoint[root];i<n&&i<roadPoint[root+1];i++) {
        bool tmpdp=dp(road[i][1]);
        res=res||tmpdp;
        tmpArr.push_back(tmpdp);
    }
    if (res) {
        hasVisit.push_back(root);
        for(int i=roadPoint[root],j=0;i<n&&i<roadPoint[root+1];i++,j++) {
            if (!tmpArr[j]) {
                isRoot.push_back(road[i][1]);
            }
        }
    }
    return res;
}

int main(){
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++)
        cin>>score[i];
    for(int i=1;i<=k;i++)
        cin>>recom[i];
    roadPoint[1]=1;
    int tmp=roadPoint[1];
    for(int i=1,j=1;i<=m;i++){
        cin>>road[i][0];
        cin>>road[i][1];
        if (road[i][0]!=roadPoint[j]) {
            roadPoint[++j]=i;
            tmp=road[i][0];
        }
    }
    
    isRoot.push_back(0);
    dp(1);
    m=m-int(hasVisit.size());
    vector<vector<int>> g(isRoot.size(),vector<int>(m+1,0));
    for (int i=1; i<isRoot.size(); i++) {
        for (int j=1; j<=m; j++) {
            for (int t=0; t<=j; t++) {
                if (g[i][j]) {
                    <#statements#>
                }
            }
        }
    }
    
    return 0;
}
