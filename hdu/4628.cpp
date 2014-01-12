#include<cstdio>
#include<cstring>
#include<algorithm>
char in[20];
bool par[1<<17];
int dp[1<<17];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",in);
        int len = strlen(in);
        memset(par,false,sizeof(par));
        memset(dp,0,sizeof(dp));
        par[0] = true;
        char temp[20];
        for(int i=1;i<(1<< len);i++){
            int k=0;
            for(int j=0;j<len;j++){
                if(i&(1<<j)){
                    temp[k++] = in[j];
                }
            }
            bool ok = true;
            for(int j=0;j<=k/2;j++){
                if(temp[j]!=temp[k-j-1])
                    ok = false;
            }
            par[i] = ok;
        }
        for(int i=1;i<(1<< len);i++){
            dp[i] = 0x3f3f3f3f;
            for(int j=i;j>0;j=(j-1)&i){
                if(par[j])
                    dp[i] = std::min(dp[i],dp[i^j]+1);
            }
        }
        printf("%d\n",dp[ (1<<len)-1]);
    }

}
