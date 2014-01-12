#include<cstdio>
using namespace std;
typedef long long ll;
ll n,m,task[100100];
int main(){
    scanf("%I64d%I64d",&n,&m);
    for(ll i=0;i<m;i++){
        scanf("%I64d",&task[i]);
    }
    ll ans = 0,pos = 1;
    for(ll i=0;i<m;i++){
        ll d = task[i]-pos;
        if(d<0)
            d+=n;
        ans+=d;
        pos = task[i];
        ll j = 0;
        while(task[i]==task[i+j]){
            j++;
        }
        i+=j-1;
    }
    printf("%I64d\n",ans);

}
