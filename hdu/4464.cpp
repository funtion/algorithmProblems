#include<cstdio>
char in[1000];
int main(){
    int n,t=1;
    while(scanf("%d",&n)==1)
    {
        long long ans = 0;
        for(int i=0;i<n;i++)
        {
             long long ct = 0;
             scanf("%s",in);
            for(int j=0;in[j];j++)
                ct+=in[j];
            if(ct>ans)
                ans = ct;
        }
        printf("Case %d: %I64d\n",t++,ans);
    }
}
