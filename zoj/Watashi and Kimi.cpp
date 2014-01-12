#include<cstdio>
#include<cstring>
template<typename T> inline void  swap(T &a ,T& b){
    T c=a;
    a=b;
    b=c;
}
int main(){
    int n;
    char cmd[30];
    int now,pre,stepw,stepk,i,j;
    double dp[2][100][100];
    while(scanf("%d",&n)==1){
        now = 1;
        pre = 0;
        memset(dp,0,sizeof(dp));
        dp[pre][n][0] = 1;
        stepw = stepk = 0;
        while(scanf("%s",cmd)!=EOF && cmd[0]!='E'){
            for(i=0;i<=n;i++){
                j = n-i;
                if(cmd[0]=='W'){
                    if(stepw>=n)
                        break;
                    if(i>0)
                        dp[now][i-1][j+1]+=(dp[pre][i][j]*i)/(n-stepw);//printf("%d %d %.2lf\n",i-1,j+1,dp[pre][i][j]);
                    dp[now][i][j] +=dp[pre][i][j]*(j-stepw)/(n-stepw);//printf("%d %d %d %.2lf %.2lf\n",i,j,stepw,dp[now][i][j],dp[pre][i][j]*(j-stepw)/(n-stepw));
                }else{
                    if(stepk>=n)
                        break;
                    if(j>0)
                        dp[now][i+1][j-1]+=dp[pre][i][j]*j/(n-stepk);//,printf("%d %d %.2lf %d %d\n",i+1,j-1,dp[pre][i][j],j,stepk);
                    dp[now][i][j] +=dp[pre][i][j]*(i-stepk)/(n-stepk);//printf("%d %d %d %.2lf %.2lf\n",i,j,stepw,dp[now][i][j],dp[pre][i][j]*(i-stepk)/(n-stepk));
                }


            }
            /*for(int i=0;i<=n;i++){
                    for(int j=0;j<=n;j++){
                        printf("%.2lf ",dp[now][i][j]);
                    }
                    puts("");
                }
                */
            if(i!=n+1){
                memcpy(dp[now],dp[pre],sizeof(dp[0]));
            }
            if(cmd[0]=='W')
                stepw++,stepk=0;
            else
                stepk++,stepw=0;
            swap(pre,now);
            memset(dp[now],0,sizeof(dp[now]));
        }
        printf("%.2f\n",dp[pre][n][0]);
    }
    return 0;
}
