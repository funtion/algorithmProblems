#include <iostream>
#include <cstdio>
using namespace std;
int a[100100],dp[100100],n;
int gcd(int a, int b)
{
    while( 1 )
    {
        a = a % b;
        if( a == 0 )
            return b;
        b = b % a;

        if( b == 0 )
            return a;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    fill(dp,dp+n,1);
    for(int i =1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(gcd(a[i],a[j])!=1)
            {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    //for(int i=0;i<n;i++)printf("dp[%d] = %d\n",i,dp[i]);
    printf("%d",dp[n-1]);
}
