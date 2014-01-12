#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;
struct fence
{
    ll w,l,id;
    fence(){}
    fence(ll ww,ll lll , ll idd){
        w = ww;
        l = lll;
        id = idd;
    }
}fs[3000];
ll n,l,cnt;
ll dp[4000][3000];
const ll mod = 1000000007;
int main(){
    cin>>n>>l;
    for(ll i=0;i<n;i++){
        cin>>fs[cnt].w>>fs[cnt].l;
        fs[cnt].id = i;
        if(fs[cnt].w != fs[cnt].l){
            ++cnt;
            fs[cnt].w = fs[cnt-1].l;
            fs[cnt].l = fs[cnt-1].w;
            fs[cnt].id = i;
        }
        cnt++;
    }
    //for(ll i=0;i<cnt;i++){
    //    cout<<fs[i].l<<' '<<fs[i].w<<endl;
    //}
    for(ll i=0;i<cnt;i++){
        dp[fs[i].w][i] = (dp[fs[i].w][i] +1)%mod;
    }
    for(ll i=1;i<=l;i++){
        for(ll j=0;j<cnt;j++){
            for(ll k=0;k<cnt;k++){
                //if(i==1&&j==0&&k==2)
                //    cout<<fs[j].w<<' '<<fs[k].l<<' '<<fs[j].id<<' '<<fs[k].id<<endl;
                if(fs[j].l == fs[k].w && fs[j].id !=fs[k].id&&i+fs[k].w<=l){
                    //cout<<i<<' '<<j<<' '<<k<<endl;
                    //cout<<i+fs[k].l<<"+="<<dp[i][j]<<endl;
                    dp[i+fs[k].w][k] +=dp[i][j];
                    dp[i+fs[k].w][k]%=mod;
                }
            }
        }
    }
    /*
    for(ll i=0;i<=l;i++){
        for(ll j=0;j<cnt;j++){
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }
    */
    ll ans = 0;
    for(ll i=0;i<cnt;i++){
        ans = (ans+dp[l][i])%mod;
    }
    cout<<ans<<endl;
    return 0;
}