
#include<cstdio>
#include<cstring>
#include<cmath>
#define MX 10010
typedef long long ll;
inline ll cb(ll x){
    if(x<4)
        return 0;
    return (x*(x-1)*(x-2)*(x-3))/(24);
}
ll n;
ll time[MX],pri[MX],cpr=0,mxx;
bool prime[MX],od[MX];
void init(){
    memset(time,0,sizeof(time));
    memset(prime,1,sizeof(prime));
    memset(od,0,sizeof(od));
    prime[1] = false;
    for(ll i=2;i<MX;i++){
        if(prime[i]){
            pri[cpr++]=i;
            //prllf("pri:%d\n",i);
            for(ll j=i+i;j<MX;j+=i)
                prime[j] = false;
        }
    }
    /*
    for(ll i=1;i<MX;i++){
        ll cnt = 0;
        for(ll j=0;j<cpr;j++){
            if(pri[j]>i)
                break;
            if(i%pri[j] == 0)
                cnt++;
        }
        if(cnt%2==0)
            od[i] = true;
        else
            od[i] = false;
    }*/
    for(ll i=0;i<cpr;i++){
        for(ll j=pri[i];j<MX;j+=pri[i])
            od[j] = !od[j];
    }
}
void deal(ll x){
    ll cnt = 0,p[MX];
    for(ll i=1;i<=sqrt(x);i++){
        if(x%i==0)
        {
            if(prime[i])
                p[cnt++]=i;
            if(prime[x/i]&& i != x/i)
                p[cnt++] = x/i;
        }
    }
    //prllf("xxx%d %d\n",x,cnt);

    ll k = (1<<cnt)-1;
    while(k){
        ll t=1;
        for(ll i=0;i<cnt;i++){
            if( (k&(1<<i)) != 0)
                t*=p[i];
        }
        time[t]++;
        if(t>mxx)
            mxx = t;
        k--;
    }
}
int main(){
    init();
    //prllf("%d\n",cpr);
    //return 0;
    while(scanf("%I64d",&n)!=EOF){
        ll x;
        mxx=0;
        memset(time,0,sizeof(time));
        for(ll i=0;i<n;i++){
            scanf("%I64d",&x);
            deal(x);

        }
        ll ans = cb(n);
        for(ll i=0;i<MX;i++){
            //prllf("%d %I64d  ans = %I64d\n",i,time[i],ans);
            if(od[i])
                ans-=cb(time[i]);
            else
                ans+=cb(time[i]);
        }
        printf("%I64d\n",ans);
    }
}
