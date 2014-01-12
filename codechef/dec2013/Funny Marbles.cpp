#include<iostream>
using namespace std;
typedef long long ll;
ll n,q;
ll c[1000010];
inline int lb(int x){
    return x&(-x);
}
void modify(int x,int d){
    for(;x<=n;x+=lb(x))
        c[x]+=d;
}
ll sum(int x){
    ll a = 0;
    for(;x>0;x-=lb(x))
        a+=c[x];
    return a;
}
int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>q;
    ll tmp;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        modify(i,tmp);
    }
    char cmd;
    ll a,b;
    for(int i=0;i<q;i++){
        cin>>cmd>>a>>b;

        if(cmd == 'S'){
            a++,b++;
            cout<<sum(b)-sum(a-1)<<endl;
        }
        if(cmd == 'G'){
            a++;
            modify(a,b);
        }
        if(cmd == 'T'){
            a++;
            modify(a,-b);
        }
    }
    return 0;
}
