#include <iostream>
using namespace std;
int n;
typedef long long ll;
ll ans[501],mp[501][501];
int se[501];

void add(int x){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
        {
            mp[i][j] = min(mp[i][j],mp[i][x]+mp[x][j]);
        }
    }
}
ll sum(int x){
    ll an=0;
    for(int i=x;i<=n;i++){
        for(int j=i+1;j<=n;j++)
            {
                an+=mp[se[i]][se[j]];
                an+=mp[se[j]][se[i]];
            }
    }
    return an;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>mp[i][j];
    for(int i=1;i<=n;i++)cin>>se[i];

    for(int i=n;i>0;i--){
        add( se[i] );
        ans[i] = sum(i);
    }
    //copy(ans+1,ans+n,ostream_iterator<ll>(cout,' '));
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
}
