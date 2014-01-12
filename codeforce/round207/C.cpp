#include<cstdio>
#include<cstring>
int ans[410000];
int a[410000],b[410000],c[410000];
int main(){
    int m,n;

    scanf("%d%d",&m,&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",a+i,b+i,c+i);
    }
    memset(ans,0,sizeof(ans));
    for(int i=n-1;i>=0;i--){
        int t = ans[c[i]];
        memset(ans+a[i],c[i],(b[i]-a[i])*sizeof(int));
        ans[c[i]] = t;
    }
    for(int i=1;i<=m;i++)
        printf("%d ",ans[i]);
}
