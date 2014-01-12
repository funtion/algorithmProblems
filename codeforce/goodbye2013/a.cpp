#include <iostream>
using namespace std;
int a,b,c;
int main(){
    cin>>a>>b;
    int ans = 0;
    while(a){
        ans+=a;
        c+=a;
        a = c/b;
        c -=a*b;
    }
    cout<<ans<<endl;
    return 0;
}