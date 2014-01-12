#include <iostream>
using namespace std;
typedef unsigned long long ll;
ll ans;
ll s(ll x){
    ll ans = 0;
    while(x){
        ans++;
        x/=10;
    }
    return ans;
}
ll force(ll w,ll m,ll k){
    for(ll i=0;;i++){
        ll cs = k*s(m+i);

        if ( w>=cs)
            w -=cs; 
        else
            return i;
    
    }
}
int main()
{
    ll w,m,k;
    cin>>w>>m>>k;
    //cout<<force(w,m,k)<<endl;
    ll len = s(m);
    ll ten = 1;
    for(ll i =0 ;i<len;i++)
        ten*=10;
    ll rm = ten - m;
    //cout<<""<<rm<<endl;
    //cout<<len * rm *k <<endl;
    if( len * rm *k >= w){
        ans = w / (k*len);
        //cout<<"ddd\n";
    }else{
        ans = rm;
        w -= k*len*rm;
        while ( true ){
            len++;
            ll tp = k*len*(ten*9);
            //cout<<w<<' '<<tp<<endl;
            if (w > tp){
                w-=tp;
                
                ans+=ten*9;
                ten*=10;
            }else{
                break;
            }
            
        }
        ll tp = w/(k*len);
            ans+=tp;
    }
    cout<<ans<<endl;
    
    return 0;
}