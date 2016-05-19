#include<iostream>
#include<vector>
using namespace std;
int n;
int arr[100][100];
int res[101];
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++)
            cin>>arr[i][j];
    }
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=i;j++){
            res[j]=max(res[j],res[j+1])+arr[i][j];
        }
    }
    cout<<res[0]<<endl;
    return 0;
}
