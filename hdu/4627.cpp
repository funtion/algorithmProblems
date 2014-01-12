#include<iostream>
#include<algorithm>
typedef long long ll;
using namespace std;
inline ll lcm(ll x,ll y){
    return x*y/__gcd(x,y);
}
ll cal1(ll x){
    ll ans = 0,tp;
    for(ll i=1;i<=x;i++){
        tp = lcm(i,x-i);
        ans = max(ans,tp);
    }
    return ans;
}
ll cal2(ll x){
    ll ans = 0,a=x/2,b=x-a,tp;
    for(ll i=-5;i<=5;i++){
        tp = lcm(a+i,b-i);
        ans = max(ans,tp);
    }
    return ans;

}
int main(){
    int t;
    cin>>t;
    ll n;
    while(t--){
        cin>>n;
        if(n<=10){
            cout<<cal1(n)<<endl;
        }
        else{
            cout<<cal2(n)<<endl;
        }

    }
    return 0;
}
