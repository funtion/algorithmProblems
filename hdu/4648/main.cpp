#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;
ll n,m,a[100101],sum[100101];
map<ll,ll> mp;
int main()
{
    while(scanf("%I64d%I64d",&n,&m) == 2){
        for(ll i=0;i<n;i++)scanf("%I64d",&a[i]);
        sum[0] = (a[0]+m)%m;
        for(ll i=1;i<n;i++)sum[i] = (sum[i-1]+a[i]+m)%m;
        mp.clear();
        ll ans = 0;
        for(ll i=0;i<n;i++){
            if(mp.find(sum[i]) == mp.end()){
                mp.insert(pair<ll,ll>(sum[i],i));
            }else{
                ans = max(ans,i-mp[sum[i]]);
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
