//看题不仔细
#include<iostream>
#include<vector>
using namespace std;
int m;
int n,p,w,h;
int main(){
    cin>>m;
    while(m--){
        cin>>n>>p>>w>>h;
        vector<int> arr(n,0);
        for(int i=0;i<arr.size();i++){
            cin>>arr[i];
        }
        int size=min(w,h);
        int num=0;
        for(;size>=1;size--){
            num=0;
            int row=(w/size);
            int col=(h/size);
            for(int j=0;j<arr.size();j++){
                num+=(arr[j]+row-1)/row;
                if((num+col-1)/col>p)
                    break;
            }
            if((num+col-1)/col<=p){
                cout<<size<<endl;
                break;
            }
        }
    }
    return 0;
}
