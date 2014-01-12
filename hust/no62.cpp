#include<iostream>
using namespace std;
int dp[10][3];
void init()
{
    dp[0][0] = 1;
    for(int i=1;i<=10;i++){
        dp[i][0] = dp[i-1][0]*9-dp[i-1][2];
        dp[i][1] = dp[i-1][0]+dp[i-1][1]*10+dp[i-1][2];
        dp[i][2] = dp[i-1][0];
    }
}
bool force(int x){
    int bit[10];
    for(int i=0;i<10;i++)
    {
        bit[i] = 0;
    }
    int y = x,len = 0;
    while(y)
    {
        bit[len] = y%10;
        y/=10;
        len++;
    }
    for(int i=0;i<len;i++)
    {
        if(bit[i] == 4)
           return false;
        if(bit[i] == 2 && bit[i+1] == 6)
            return false;
    }
    return true;
}
int f(int x){
    int bit[10];
    for(int i=0;i<10;i++)
    {
        bit[i] = 0;
    }
    int y = x,len = 0;
    while(y)
    {
        bit[len] = y%10;
        y/=10;
        len++;
    }
    int ans = 0;
    for(int i=len-1;i>=0;i--)
    {
        for(int j=0;j<bit[i];j++){
            if( j != 4 )
            {
                if(j==2 && bit[i+1]==6)
                    continue;
                if(j==6)
                {
                    ans+=dp[i][0]-dp[i][2];
                }
                else
                {
                    ans+=dp[i][0];
                }
            }
        }
        if(bit[i]==4||(bit[i]==2&&bit[i+1]==6))
        {
            break;
        }
    }
    return ans;
}
int main()
{
    init();
    //for(int i=0;i<10;i++)
    //{
    //   cout<<dp[i][0]<<' '<<dp[i][1]<<' '<<dp[i][2]<<endl;
   // }
    int m,n;
    while(cin>>m>>n&&m+n)
    {
        int ans = f(n+1)-f(m);
        cout<<ans<<endl;
        /*
        int a = 0;
        for(int i=m;i<=n;i++){
            if(force(i))
                a++;
        }
        cout<<a<<endl;
        cout<<m<<':'<<f(m)<<' '<<n+1<<':'<<f(n+1)<<endl;
        */
    }
}
