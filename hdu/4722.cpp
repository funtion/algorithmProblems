#include<cstdio>
#include<cstring>
typedef long long ll;
ll dp[20][10];
void init(){
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    //for(int i=0;i<=9;i++)
    //    dp[1][i] = 1;
    for(int len=1;len<20;len++){
        for(int i=0;i<=9;i++){
            for(int j=0;j<=9;j++){
                    dp[len][i]+=dp[len-1][j];
            }
            //printf("%d %d %I64d\n",len,i,dp[len][i]);
        }
    }
}
ll f(ll x){
    int num[20],len=0;
    while(x){
        num[len++] = x%10;
        x/=10;
    }
    ll ans = 0,cnt=0;
    for(int i=len-1;i>=0;i--){
        for(int j=0;j<num[i];j++){
            ans+=dp[i][(100-cnt-j)%10];
        }
        cnt+=num[i];
        cnt%=10;
    }
    return ans;
}
int main(){
    init();
    int t;
    ll a,b,x,ans;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){

        //scanf("%I64d",&x);
        //printf("%I64d\n",f(x));
        scanf("%I64d%I64d",&a,&b);
        if(a==0){
            if(b==0)
                ans = 1;
            else
                ans = f(b+1);
        }else{
            ans = f(b+1)-f(a);
        }
        printf("Case #%d: %I64d\n",cs,ans);

    }
}
