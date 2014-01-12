#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
int n,t;
ll pow(ll x,int n){
    if(n==0)return 1;
    if(n==1)return x;
    ll tmp = pow(x,n/2)%mod;
    if(n%2==0)
        return (tmp*tmp)%mod;
    else
        return ((tmp*tmp)%mod*x)%mod;
}
ll ni = pow(30,mod-2);
ll sum(ll n){
    ll ans = n%mod;
    ans = (ans*(n+1)%mod)%mod;
    ans = (ans*(2*n+1)%mod)%mod;
    ans = (ans*(3*(n*n)%mod+(3*n-1+mod)%mod)%mod)%mod;
    ans = (ans*ni)%mod;
    return ans;
}
ll calc(ll x){
    ll tot = sum(x);
   // cout<<"sum"<<x<<' '<<tot<<endl;
    vector<ll> v;
    for(ll i=2;i*i<=x;i++){
        if(x%i==0){
            v.push_back(i);
            while(x%i==0){
                x/=i;
            }
        }
    }
    if(x>1){
        v.push_back(x);
    }
    //for(int i=0;i<v.size();i++){
    //    cout<<"vvv"<<i<<' '<<v[i]<<endl;
    //}
    int mask = (1<<(v.size()))-1,cnt;
    ll a,b,c;
    while(mask){
        a = 1;
        cnt = 0;
        for(int i=0;i<v.size();i++){
            if(mask&(1<<i)){
                a*=v[i];
                cnt++;
            }
        }
        b = n/a;
        c = (pow(a,4)*sum(b))%mod;
        if(cnt%2 == 1 ){
            tot = (tot-c+mod)%mod;
        }else{
            tot = (tot+c)%mod;
        }
        mask--;
    }
    return tot;
}
int main(){

    cin>>t;
    while(t--){
        cin>>n;
        ll ans = calc(n);
        cout<<ans<<endl;
    }
}
