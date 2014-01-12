#include<iostream>
#include<cstdio>
typedef long long ll;
using namespace std;
bool ck(ll x){
    ll y = 0;
    while(x){
        y+=x%10;
        x/=10;
    }
    return y%10==0;
}
int main(){
    ll n,cnt=0;
    freopen("out.txt","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        if(ck(i))
        {
            cout<<++cnt<<' '<<i<<endl;
        }

    }
}
