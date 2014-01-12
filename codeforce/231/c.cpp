#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MAX = 100010;
ll n,k;
ll a[MAX],cnt[MAX];
bool cal(ll i,ll x){
    if( x > i)
        return false;
    ll kk = a[i]*x-(cnt[i]-cnt[i-x]);
    return kk <= k;
}
ll solve(ll i){
    ll l = 0, h = n+1,mid;
    while(h-l>1){
        mid = (l+h)/2;
        if(cal(i,mid))
            l = mid;
        else
            h = mid;
    }
    return l;
}

int main(){
    cin>>n>>k;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++)
        cnt[i] = cnt[i-1]+a[i];
    ll ans = -1,aa;
    for(ll i=1;i<=n;i++){
        ll tmp = solve(i);
        //cout<<i<<' '<<tmp<<endl;
        if(tmp>ans){
            ans = tmp;
            aa = a[i];
        }
    }
    cout<<ans<<' '<<aa<<endl;
}