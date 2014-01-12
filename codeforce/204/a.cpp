#include <iostream>
using namespace std;
typedef long long ll;
ll ten[20];
ll dp(ll x){
    int num[20];
    int len = 0;
    for(int i=0;x;i++){
        num[i] = x%10;
        x/=10;
        len = i;
    }
    ll ans = 0;
    for(int i=len;i>=0;i--){
        ans += (num[i]-1)*ten[i-1];
        
    }

}
int main(){
    ten[0] = 1;
    for(int i=1;i<20;i++)
        ten[i] = 10*ten[i-1];
    ll x,y;
    cin>>x>>y;
    cout<<(dp(x)-dp(y-1))<<endl;
}
