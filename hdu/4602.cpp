#include<iostream>
#define md (ll)(1e9+7)
using namespace std;
typedef long long ll;
ll pmd(ll x,ll y){
    if(y==0)
        return 1;
    if(y==1)
        return x%md;
    ll k = pmd(x,y/2)%md;
    if(y%2==0)
        return (k*k)%md;
    else
        return (k*k*x)%md;
}
ll f(ll x){
    if(x<0)
        return 0;
    if(x==0)
        return 1;
    if(x==1)
        return 2;
    ll ans = pmd(2,x-2)%md;
    ans = (ans*((x+3)%md))%md;
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    int t;
    ll n ,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        cout<<f(n-k)<<endl;
    }
}
/*
1  1
2  2   1
3  5   2   1
4  12  5   2   1
5  28  12  5   2   1



0 1 2 3   4
1 2 5 12 28 //http://oeis.org/A045623
f(n+1) = f(n)*2+2^(n-1)
g(n,k) = f(n-k)


*/
