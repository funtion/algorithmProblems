#include<iostream>
#define MAX 2000
using namespace std;
int n,m;
int c[MAX][MAX];
int tp[500000];
inline int lowbit(int x)
{
    return x&(-x);
}
void ad(int x,int y)
{
    for(int i=x;i<MAX;i+=lowbit(i))
    {
        for(int j = y;j<MAX;j+=lowbit(j))
        {
            c[i][j]++;
        }
    }
}
int su(int x,int y)
{
    int ans = 0;
    for(int i=x;i>0;i-=lowbit(i))
    {
        for(int j=y;j>0;j-=lowbit(j))
            ans+=c[i][j];
    }
    return ans;
}
int ge(int x,int y)
{
    int tot = su(x,MAX-10);
    int xx = su(x,y-1);
    return tot-xx;
}
int main()
{
    cin>>n>>m;
    int a,b,cnt;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        ad(a,b);
    }

    for(int i=0;i<m;i++)
    {
        cin>>cnt;
        int ans = 0;
        for(int i=1;i<=cnt;i++)
            cin>>tp[i];
        for(int i=1;i<=cnt;i++)
        {
            ans += ge(tp[i],tp[i])-ge(tp[i-1],tp[i]);
        }
        cout<<ans<<endl;
    }

    return 0;
}
