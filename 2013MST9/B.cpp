#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxn 100
int match[maxn];
bool map[maxn][maxn];
bool v[maxn];
int n,m;
int pp[maxn][maxn];
bool as[maxn];
bool dfs(int p)
{
    int i;
    for(i=n+1;i<=n+n;i++)
    {
        if(map[p][i]&&!v[i])
        {
            v[i]=1;
            if(match[i]==-1||dfs(match[i]))
            {
                match[i]=p;
                return 1;
            }
        }
    }
    return 0;
}
int Hungry()
{
    int i;
    int ans=0;
    for(i=1;i<=n;i++)
    {
        memset(v,0,sizeof(v));
        if(dfs(i))
            ans++;
    }
    return ans;
}
int main()
{
    int i,j,k;
    while(scanf("%d%d",&n,&k)==2){
        memset(pp,0,sizeof(pp));

        for(m=1; m<=k; m++)
        {
            scanf("%d%d",&i,&j);
            j+=n;
            map[i][j]=1;
            pp[i][j] = m;
        }
        for(int i=1;i<=n;i++){
            for(int j=n+1;j<=n+n;j++){
                printf("%d ",map[i][j]?1:0);
            }
            puts("");
        }
        memset(match,-1,sizeof(match));
        int an = Hungry();
        printf("%d\n",k-an);

        memset(as,false,sizeof(as));
        for(int i=1;i<=n;i++)
           printf("%d-%d %d\n",i,match[i],pp[i][match[i]]);
       for(int i=1;i<=k;i++){
            printf("%d  %d\n",i,as[i]);
        }
        for(int i=1;i<=n;i++){
            as[pp[i][match[i]>0?match[i]:0]]=true;
        }
        for(int i=1;i<=n;i++){
            if(!as[i])
                printf("%d ",i);
        }
        printf("\n");
    }

}
