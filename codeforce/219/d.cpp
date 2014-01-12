#include<iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstdio>
typedef long long ll;
using namespace std;
const ll MAXN = 200010;
ll n;
vector<ll> tree[MAXN][2];
ll fa[MAXN],ca[MAXN],cb[MAXN],cc[MAXN];
ll ans[MAXN];
void dfs(ll pre,ll x){
    ll sa = tree[x][0].size(),sb = tree[x][1].size();
    ll aa = 0,bb = 0 ;
    for(ll i=0;i<sa;i++){
        ll next = tree[x][0][i];
        if(next!=pre){
            aa++;
            fa[next] = x;
            dfs(x,next);
            aa+=ca[next];
            bb+=cb[next];
        }
    }
    for(ll i=0;i<sb;i++){
        ll next = tree[x][1][i];
        if(next!=pre){
            bb++;
            fa[next] = x;
            dfs(x,next);
            aa+=ca[next];
            bb+=cb[next];
        }
    }
    ca[x] = aa;
    cb[x] = bb;
}
void dfs2(ll pre,ll x){
    ll sa = tree[x][0].size(),sb = tree[x][1].size();
    for(ll i=0;i<sa;i++){
        ll next = tree[x][0][i];
        if(next != pre){
            cc[next] = cb[x]+cc[x]-cb[next]+1;
            dfs2(x,next);
        }
    }
    for(ll i=0;i<sb;i++){
        ll next = tree[x][1][i];
        if(next != pre){
            cc[next] = cb[x]+cc[x]-cb[next]-1;
            dfs2(x,next);
        }
    }
}
int main(){
    cin>>n;

    ll a,b;//,a0,b0;
    for(ll i=0;i<n-1;i++){
        cin>>a>>b;
        ///if(!i){
        //    a0 = a,b0=b;
        //}
        tree[a][0].push_back(b);
        tree[b][1].push_back(a);
    }
    dfs(0,1);
    dfs2(0,1);
    cc[1] = 0;
    for(ll i=1;i<=n;i++){
        ll fat = fa[i];
        ans[i] = cb[i]+cc[i];
    }
    ll *p = min_element(ans+1,ans+n+1);
    //if(n==200000&&a0==200000&&b0==1){
        //for(ll i=1;i<=n;i++){
        //    cout<<ca[i]<<' '<<cb[i]<<' '<<cc[i]<<' '<<ans[i]<<endl;
        //}
        //cout<<ca[200000]<<' '<<cb[200000]<<' '<<cc[200000]<<' '<<ans[200000]<<endl;
    //}
    
    vector<ll> o;
    for(ll i=1;i<=n;i++)
        if(ans[i] == *p)
            o.push_back(i);
    cout<<*p<<endl;
    for (std::vector<ll>::iterator i = o.begin(); i != o.end(); ++i)
    {
        cout<<*i<<' ';
    }
    cout<<endl;
    return 0;
}
