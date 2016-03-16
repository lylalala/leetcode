#include<iostream>
#include<queue>
using namespace std;
long long N;
long long Q;
long long data[100005];
long long ok(long long pos){
    if (pos<1) {
        pos=1;
    }
    long long tempQ=0;
    priority_queue<int> q;
    long long count=1;
    long long i=0;
    for(i=0;i<pos;i++)
        q.push(data[i]);
    for(i=i;i<N;i++){
        tempQ+=(q.top()*(count++));
        q.pop();
        q.push(data[i]);
    }
    for(long long j=0;j<pos;j++){
        tempQ+=(q.top()*(count++));
        q.pop();
    }
    return tempQ;
}
int main(){
    cin>>N>>Q;
    for(long long i=0;i<N;i++)
        cin>>data[i];
    
    long long first=0;
    long long last=N-1;
    long long middle;
    while(first<last){
        middle=(first+last)>>1;
        if(ok(middle)>Q){
            first=middle+1;
        }else{
            last=middle;
        }
    }
    if(first>N-1)
        cout<<-1<<endl;
    else if(first==0)
        cout<<1<<endl;
    else
        cout<<first<<endl;
    return 0;
}
