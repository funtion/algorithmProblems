#include <iostream>
using namespace std;
typedef long  ll;
ll in[1010][1010],in2[1010][1010],in5[1010][1010],ans2[1010][1010],ans5[1010][1010];
    char pr2[1010][1010],pr5[1010][1010];
    char st[2010];
inline ll ct(ll x,ll d){
    ll a=0;
    while(x%d==0)
    {
        a++;
        x/=d;
    }
    return a;
}
int main()
{
    int n;
    bool n0=false;
    int x0,y0;

    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>in[i][j];
            if(in[i][j]==0)
            {
                n0=true;
                x0=i;
                y0=j;
                in2[i][j]=in5[i][j] = 1;
                continue;
            }
            in2[i][j] = ct(in[i][j],2);
            in5[i][j] = ct(in[i][j],5);
        }
    }
    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<in5[i][j]<<' ';
        }
        cout<<endl;
    }
    */
    ans2[1][1] = ct(in[1][1],2);
    ans5[1][1] = ct(in[1][1],5);
    for(int i=2;i<=n;i++)
    {
            ans2[1][i] = in2[1][i]+ans2[1][i-1];
            ans2[i][1] = in2[i][1]+ans2[i-1][1];
            pr2[1][i] = 'R';pr2[i][1] = 'D';

            ans5[1][i] = in5[1][i]+ans5[1][i-1];
            ans5[i][1] = in5[i][1]+ans5[i-1][1];
            pr5[1][i] = 'R';pr5[i][1] = 'D';
    }
    //cout<<"**"<<ans5[1][2]<<"**"<<in5[1][1]<<"**"<<ans5[1][2]<<endl;
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=n;j++)
        {
            if(ans2[i-1][j]<ans2[i][j-1])
            {
                ans2[i][j] = ans2[i-1][j]+in2[i][j];
                pr2[i][j] = 'D';
            }
            else
            {
                ans2[i][j] = ans2[i][j-1]+in2[i][j];
                pr2[i][j] = 'R';
            }

            if(ans5[i-1][j]<ans5[i][j-1])
            {
                ans5[i][j] = ans5[i-1][j]+in5[i][j];
                pr5[i][j] = 'D';
            }
            else
            {
                ans5[i][j] = ans5[i][j-1]+in5[i][j];
                pr5[i][j] = 'R';
            }
        }
    }


    /*
    cout<<"ans\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<ans5[i][j]<<' ';
        }
        cout<<endl;
    }

 */
    int aa = min(ans2[n][n],ans5[n][n]);
    if(n0&&aa>1){
        cout<<1<<endl;
        if(y0==1){
            for(int i=2;i<=n;i++)
                cout<<'D';
            for(int i=2;i<=n;i++)
                cout<<'R';
            return 0;
        }
        else if(x0==1){
            for(int i=2;i<=n;i++)
                cout<<'R';
            for(int i=2;i<=n;i++)
                cout<<'D';
            return 0;
        }
        for(int i=2;i<=x0;i++){
            cout<<'D';
        }
        for(int i=2;i<=n;i++){
            cout<<'R';
        }
        for(int i=x0+1;i<=n;i++){
            cout<<'D';
        }
        //for(int i=y0;i<=n;i++){
        //    cout<<'D';
        //}
        return 0;
    }
    if(ans2[n][n]<ans5[n][n])
    {
        cout<<ans2[n][n]<<endl;
        int cx=n,cy=n;
        for(int i=n+n;i>=2;i--)
        {
            st[i] = pr2[cx][cy];
            if(st[i]=='D'){
                cx--;
            }
            else{
                cy--;
            }
        }
    }else{
        cout<<ans5[n][n]<<endl;
        int cx=n,cy=n;
        for(int i=n+n;i>=2;i--)
        {
            st[i] = pr5[cx][cy];
            if(st[i]=='D'){
                cx--;
            }
            else{
                cy--;
            }
        }
    }
    st[n+n+1]='\0';
     cout<<st+3;
}
