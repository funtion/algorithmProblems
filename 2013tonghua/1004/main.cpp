#include <iostream>
#include <cstdio>
using namespace std;
long long m,n,a,b;
long long F[100100],ans[100100];
long long sa[100100],sb[100100];
long long f(long long x){
    if(F[x]==x)
        return x;
    return F[x] = f(F[x]);
}
int main()
{
    while(scanf("%I64d%I64d",&n,&m)==2){
        for(long long i=0;i<n;i++){
            F[i] = i;
        }

        for(long long i=0;i<m;i++){
            scanf("%I64d%I64d",&a,&b);
            sa[i]= a;
            sb[i] = b;
        }
        ans[m]=n;
        for(int i=m-1;i>=0;i--){
            long long fa = f(sa[i]);
            long long fb = f(sb[i]);
            if(fa==fb){
                ans[i] = ans[i+1];
            }else{
                F[fa] = fb;
                ans[i] = ans[i+1]-1;
            }
        }

        for(long long i=1;i<=m;i++){
            printf("%I64d\n",ans[i]);
        }

    }
    return 0;
}
