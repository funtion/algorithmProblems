#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll ck(ll n){
    ll ans = 0;
    for(ll i=1;i<=n;i++)
        ans^=i;
    return ans;
}
int main(){
    freopen("xorsum.in","r",stdin);
    freopen("xorsum.out","w",stdout);
    ll n;
    while(cin>>n){
        ll ans = 0;
        int len = 0;
        ll one = 1;
        for(int i=0;i<62;i++){
            //cout<<(one<<i)<<endl;
            if(n&(one<<i)){
                //cout<<n<<' '<<i<<' '<<(one<<i)<<' '<<(n&(one<<i))<<endl;
                len = i;
            }

        }

        //cout<<"len= "<<len<<endl;
        ll a = n%2,b = n/2;
        if(a==1){
            ans = (b%2==0)?1:0;
        }else{
            ans = (b%2==0)?0:1;
        }
        for(int i=2;i<=len+1;i++){
            ll j = 1<<i;
            ll k = (n+1)%j;
            ll t;
            if(k<=j/2)
                t = 0;
            else{
                ll kk = k-j/2;
                if(kk%2==0)
                    t = 0;
                else
                    t = 1;
            }
            //cout<<i<<' '<<j<<' ' <<k<<' '<<t<<endl;
            ans |= (t<<(i-1));
        }
        cout<<ans<<endl;
        //cout<<ck(n)<<endl;
    }
}
