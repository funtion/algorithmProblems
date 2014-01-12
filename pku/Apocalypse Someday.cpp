

#include<cstdio>
#include<cstring>
#include<climits>
typedef long long ll;
ll dp[30][4];

ll fd(ll x){
    ll ans = 0;
    int bit[30],len=0;
    ll temp = x;
    memset(bit,0,sizeof(bit));
    while(temp){
        bit[++len] = temp%10;
        temp/=10;
    }
    bool flag = false;
    for(int i=len;i;i--){

        if(!flag){
            ans+=bit[i]*dp[i-1][0];
            if(bit[i]>6){
                ans+=dp[i-1][2];
                if(bit[i+1]==6 && bit[i+2]==6){

                    ans+=dp[i-1][3]+dp[i-1][1];
                }
                else if(bit[i+1]==6){
                    ans+=dp[i-1][1];
                }
            }

            if(bit[i]==6&&bit[i+1]==6&&bit[i+2]==6)
                flag = true;
        }else{
           // printf("%d an==%I64d--",i,ans);
            ans+=(dp[i-1][3]+dp[i-1][2]+dp[i-1][1]+dp[i-1][0])*bit[i];
           // printf("%I64d\n",ans);
        }
        //printf("%d an=%I64d\n",i,ans);
    }
    return ans;
}
int main(){
    //freopen("D:\\ac\\out1.txt","w",stdout);
    //printf("%I64d\n",LLONG_MAX);
    //ten[0]=1;
    //for(int i=1;i<20;i++)
     //   ten[i] = ten[i-1]*10;
    dp[0][3] = 1;
    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[1][3] = 9;
    for(int i=2;i<=30;i++){
        dp[i][0] = dp[i-1][0]*10+dp[i-1][2];
        dp[i][1] = dp[i-1][3];
        dp[i][2] = dp[i-1][1];
        dp[i][3] = dp[i-1][1]*9+dp[i-1][2]*9+dp[i-1][3]*9;
    }
    //for(int i=0;i<10;i++){
    //   printf("%I64d %I64d %I64d %I64d\n",dp[i][0],dp[i][1],dp[i][2],dp[i][3]);
    //}
    int n;
    ll x;
    scanf("%d",&n);
    while(n--){
        scanf("%I64d",&x);
       // x = n;
        //if(x==0)
        //{
        //    puts("0");
       //    continue;
        //}

        //printf("%I64d\n",fd(x));
        //continue;

        //ll t=0;
        //while(fd(t)!=x)
        //    t++;
        //printf("%I64d\n",t-1);
        //continue;
        ll l=0,h=LLONG_MAX,mid=-1,tp;
        while(l<h){
            mid = (l+h)/2;
            tp = fd(mid);//printf("%I64d  %I64d %I64d %I64d\n",l,h,mid,tp);
            if(tp<x)
            {
                l = mid+1;
            }
            else //if(tp>x){
                h =  mid;
        }
        l--;
        while(x==fd(l))
            l--;
        //while(x<=fd(mid))
        //    mid--;
        printf("%I64d\n",l);
    }
    return 0;
}
