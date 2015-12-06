#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
    string input;
    getline(cin,input);
    int count_red=0,count_yellow=0,count_blue=0;
    stack<char> stackColor;
    for(int i=0;i<input.length();){
        if(input[i]=='<'){
            i++;
            if(input[i]=='/'){
                stackColor.pop();
            }
            else{
                stackColor.push(input[i]);
            }
            while(input[i]!='>')
                i++;
            i++;
        }else{
            if(stackColor.empty()||input[i]==' ')
                i++;
            else{
                char t=stackColor.top();
                if(t=='r')
                    count_red++;
                if(t=='y')
                    count_yellow++;
                if(t=='b')
                    count_blue++;
                i++;
            }
        }
    }
    cout<<count_red<<" "<<count_yellow<<" "<<count_blue<<endl;
    return 0;
}
