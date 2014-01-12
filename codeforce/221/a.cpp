#include <iostream>
using namespace std;
char s[1001000];
int main(){
    cin>>s;
    int pv = 0;
    for(int i=0;s[i];i++){
        if(s[i] == '^'){
            pv = i;
            break;
        }
    }
    long long l=0,r=0;
    for(int i=0;s[i];i++){
        if(s[i] != '='){
            if(i<pv){
                l += (pv-i)*(s[i]-'0');
            }else{
                r +=(i-pv)*(s[i]-'0');
            }
        }
    }
    if(l==r){
        cout<<"balance\n";
    }else if(l>r){
        cout<<"left\n";
    }else{
        cout<<"right\n";
    }
    return 0;
}