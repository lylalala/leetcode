#include<iostream>
#include<vector>
using namespace std;
int main(){
    int Q;
    cin>>Q;
    while(Q--){
        string a,b;
        cin>>a;
        cin>>b;
        vector<int> next(a.size(),0);
        next[0]=0;
        int k=0;
        for(int q=1;q<a.size();q++){
            while(k>0&&a[k]!=a[q])
                k=next[k-1];
            if(a[k]==a[q])
                k++;
            next[q]=k;
        }
        
        int res=0;
        int pos=0;
        for(int i=0;i<b.size();){
            if(pos<a.size()&&b[i]==a[pos]){
                i++;
                pos++;
                if(pos==a.size()){
                    res++;
                    pos=next.back();
                }
            }else{
                if(pos==0){
                    i++;
                }else{
                    pos=next[pos-1];
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
