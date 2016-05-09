#include<iostream>
using namespace std;
int n;
int a,b,res;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        res=b;
        while(1){
            int tmp=a%4;
            if((tmp==1||tmp==0)&&res!=0){
                a=a/4;
                res--;
            }else{
                cout<<res<<endl;
                break;
            }
        }
    }
    return 0;
}
