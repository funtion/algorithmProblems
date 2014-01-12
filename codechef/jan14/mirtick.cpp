#include <iostream>
using namespace std;
typedef long long ll;
ll n ,a,b,c;
ll l[2000];
ll adp(const ll x,const ll y){
    return (x+y)%c;
}
ll mup(ll x,ll y){
    if(y==0)
        return 0;
    if(y==1)
        return x%c;
    ll tmp = mup(x,y/2);
    tmp = adp(tmp,tmp);
    if(y%2==1)
        tmp=adp(tmp,x);
    return tmp;
}
int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>l[i];
        }
        cin>>a>>b>>c;
        char x;
        ll p=1,q=0;
        for(int i=0;i<n;i++){
            cin>>x;
            if(x=='R'){
                for(int j=i,k=n-1;j<k;j++,k--){
                    ll tmp = l[j];
                    l[j] = l[k];
                    l[k] = tmp;
                }
                ll ans = l[i];
                ans = mup(ans,p);
                ans = adp(ans,q);
                cout<<ans<<' ';
            }else if(x=='A'){
                ll ans = l[i];
                q = adp(q,a);
                ans = mup(ans,p);
                ans = adp(ans,q);
                cout<<ans<<' ';
            }else{
                ll ans = l[i];
                p = mup(p,b);
                q = mup(q,b);
                ans = mup(ans,p);
                ans = adp(ans,q);
                cout<<ans<<' ';
            }
        }
        cout<<endl;
    }
    return 0;
}