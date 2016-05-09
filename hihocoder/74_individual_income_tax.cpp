//http://hihocoder.com/contest/hiho74/problem/1

//the solution is not perfect.
//the numbers can be put into an array. Then use "for" instead of so many "if"
#include<iostream>
using namespace std;

int main(){
    //输入
    float tax;
    cin>>tax;
    
    if(tax<=45){
        cout<<int(tax/0.03+3500)<<endl;
        return 0;
    }
    if(tax<=345){
        cout<<int((tax-45)/0.1+5000)<<endl;
        return 0;
    }
    if(tax<=1245){
        cout<<int((tax-345)/0.2+8000)<<endl;
        return 0;
    }
    if(tax<=7745){
        cout<<int((tax-1245)/0.25+12500)<<endl;
        return 0;
    }
    if(tax<=13745){
        cout<<int((tax-7745)/0.3+38500)<<endl;
        return 0;
    }
    if(tax<=22495){
        cout<<int((tax-13745)/0.35+58500)<<endl;
        return 0;
    }
    cout<<int((tax-22495)/0.45+83500)<<endl;
    return 0;
}
