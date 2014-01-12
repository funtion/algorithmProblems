#include<cstdio>
#include<algorithm>
int a[2000],b[2000];
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        std::sort(a,a+n+1);
        for(int i=0;i<=n-1;i++)
            b[i] = a[i+1]-a[i]-1;
        int ans = b[n-1],k=n-1;
        while((k=k-2)>=0){
            ans^=b[k];
        }
        if(ans ==0)
            puts("Bob will win");
        else
            puts("Georgia will win");

    }
    return 0;
}
