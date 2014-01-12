#include <cstdio>
int n,a[200010],ans[200010];
long long sum;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]*n == sum){
                ans[cnt++] = i+1;

        }
    }
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++){
        printf("%d ",ans[i]);
    }

}
