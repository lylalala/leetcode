#include<iostream>
#include<vector>
using namespace std;
int Q;
string process(string a){
    string res(a.length()*2+1,'#');
    int j=1;
    for(int i=0;i<a.length();i++){
        res[j]=a[i];
        j+=2;
    }
    return res;
}
int main(){
    cin>>Q;
    string a;
    while(Q--){
        cin>>a;
        a=process(a);
        vector<int> p(a.size(),1);
        int maxID=0;
        int id=0;
        int res=0;
        for(int i=1;i<a.length();i++){
            if(maxID>i){
                p[i]=min(p[2*id-i],maxID-i+1);
            }else{
                p[i]=1;
            }
            while(i+p[i]<a.size()&&i-p[i]>=0&&a[i+p[i]]==a[i-p[i]])
                p[i]++;
            if(i+p[i]-1>maxID){
                maxID=i+p[i]-1;
                id=i;
            }
            res=max(res,p[i]-1);
        }
        cout<<res<<endl;
    }
    return 0;
}
