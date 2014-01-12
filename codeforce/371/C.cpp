#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
typedef long long ll;
char str[200];
// b s c
ll x[3];
ll len;
ll n[3],b[3];
ll ru;
int main(){
    cin>>str;
    for(ll i=0;str[i];i++){
        if(str[i] == 'B')
           x[0]++;
        if(str[i] == 'S')
            x[1]++;
        if(str[i] == 'C')
            x[2]++;
        len = i+1;
    }
    for(ll i=0;i<3;i++)
        cin>>n[i];
    for(ll i=0;i<3;i++)
        cin>>b[i];
    cin>>ru;
    //cout<<"input ol\n";
    ll ans = 1000;
    for(ll i=0;i<3;i++){
        if(x[i] != 0){
            ans = min(ans,n[i]/x[i]);
        }
    }
    ll ans2 = 0;
    for(ll i=0;i<3;i++){
        n[i] -= x[i]*ans;
    }
    ///for(ll i=0;i<3;i++){
   ///     cout<<n[i]<<endl;
   /// }
    ll cost = 0;
    for(ll i=0;i<3;i++){
        cost+=x[i]*b[i];
    }
    //cout<<"cost = "<<cost<<endl;
    for(ll i=0;i<=205;i++){
        for(ll j=0;j<=205;j++){
            for(ll k=0;k<=205;k++){
                if(i*b[0]+j*b[1]+k*b[2]>ru)
                    break;
                ll aa = x[0]==0?99999:(n[0]+i)/x[0];
                ll  bb = x[1]==0?99999: (n[1]+j)/x[1];
                ll cc = x[2] == 0?99999:(n[2]+k)/x[2];
                ll dd = (ru - (i*b[0]+j*b[1]+k*b[2]))/cost;
                //cout<<"test "<<i<<' '<<j<<' '<<k<<endl;
                //cout<<aa<<' '<<bb<<' '<<cc<<' '<<dd<<endl;
                ans2 = max(ans2,dd+min(aa,min(bb,cc)));
                /*
                ///bool fd = 0;
                if(i==0&&j==50&&k==50){
                   /// fd = 1;
                    cout<<"test "<<i<<' '<<j<<' '<<k<<endl;
                    cout<<aa<<' '<<bb<<' '<<cc<<' '<<dd<<endl;
                    cout<<(i*b[0]+j*b[i]+k*b[2])<<b[0]<<' '<<b[1]<<' '<<b[2]<<endl;
                }
                */
            }
        }
    }
    cout<<ans+ans2<<endl;
    return 0;
}
