#include <iostream>
using namespace std;
int in[100100],dp[100100];
int m,n,l,r;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>in[i];
    for(int i=2;i<=n-1;i++)
    {
        if(in[i]<in[i-1]&&in[i]<in[i+1])
        {
            dp[i] = dp[i-1]+1;
        }
        else
        {
            dp[i] = dp[i-1];
        }
    }
    while(m--)
    {
        cin>>l>>r;
        if(l==r||l==r-1)
            cout<<"Yes\n";
        else if(dp[r-1]-dp[l]== 0)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}
