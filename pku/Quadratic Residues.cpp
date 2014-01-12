#include<cstdio>
typedef long long ll;
ll pw(ll x,ll n,ll m){
    if(n==0)
        return 1;
    ll a = pw(x,n/2,m)%m,b= (a*a)%m;
    if(n%2!=0)
        b = (b*x)%m;
    return b;
}
int main(){
    int t;
    ll a,p;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        scanf("%I64d%I64d",&a,&p);
        a%=p;
        a = (a+p)%p;
        printf("Scenario #%d:\n",cs);
        if(pw(a,(p-1)/2,p)==1)
            puts("1");
        else
            puts("-1");
        puts("");

    }
}
