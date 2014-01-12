#include <iostream>
using namespace std;
char s[110];
int n,ct,len;
int main(){
    cin>>s>>n;
    for(int i=0;s[i];i++){
        if(s[i]=='T')
            ct++;
        len=i;
    }
    len++;
    if(ct<n){
        if( (n-ct)%2==0){
            cout<<len;
        }else{
            cout<<len-1;
        }
    }else if(ct==n){
        cout<<len;
    }else{
        cout<<n;
    }
}
