#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll go(ll n,ll a,ll b){
    ll i=0,x=0,y=0;
    ll ans = 0,m;
    while(i<n){
        m = min(a-x,b-y);
        if(i+m>=n)m=n-i;
        ans+=m*abs(x-y);
        x = (x+m)%a;
        y = (y+m)%b;
        i+=m;
    }
    return ans;
}
int main(){
    int t;
    ll n,a,b;
    cin>>t;
    while(t--){
        cin>>n>>a>>b;
        ll lcm = a*b/__gcd(a,b);
        ll ans;
        if(lcm>=n){
            ans = go(n,a,b);
        }else{
            ans = (n/lcm)*go(lcm,a,b)+go(n%lcm,a,b);
        }
        cout<<ans<<endl;

    }
}
