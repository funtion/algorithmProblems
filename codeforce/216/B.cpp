#include<iostream>
using namespace std;
int main()
{
    int n,k,l,r,sall,sk;
    int ans[2000];
    cin>>n>>k>>l>>r>>sall>>sk;
    int avg = sall/n;
    int dt = sall - avg*n,dtk = sk-avg*k;
    for(int i=0;i<n;i++)
        ans[i] = avg;
    if(dt < dtk)
    {
        for(int i=0;i<dtk-dt;i++)
            ans[i%(n-k)]--;
        for(int i=0;i<dtk;i++)
            ans[n-k+i%k]++;
    }
    else if(dt >= dtk)
    {
        for(int i=0;i<dt-dtk;i++)
            ans[i%(n-k)]++;
        for(int i=0;i<dtk;i++)
            ans[n-k+i%k]++;
    }
    for(int i=0;i<n;i++)
        cout<<ans[i]<<' ';
    return 0;
}
