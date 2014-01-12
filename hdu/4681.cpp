#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#define mx 1010
typedef long long ll;
using namespace std;
ll dp1[mx][mx],dp2[mx][mx];
ll f1[mx][2],f2[mx][2],cf1,cf2;
void lcs(const string&a,const string &b,ll dp[mx][mx])
{
    ll la = a.length(),lb = b.length();
    if(a[0]==b[0])
        dp[0][0] = 1;
    else
        dp[0][0] = 0;
    for(ll i=1; i<la; i++)
    {
        if(a[i] == b[0])
            dp[i][0] = max(1LL,dp[i-1][0]);
        else
            dp[i][0] = dp[i-1][0];
    }
    for(ll i=1; i<lb; i++)
    {
        if(b[i]==a[0])
            dp[0][i] = max(1LL,dp[0][i-1]);
        else
            dp[0][i] = dp[0][i-1];
    }
    for(ll i=1; i<la; i++)
    {
        for(ll j=1; j<lb; j++)
        {
            if(a[i] == b[j])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
}
void fd(const string& s,const string &c,ll f[mx][2],ll &ct){
    ll ls = s.length(),lc = c.length();
    for(ll i=0;i<ls;i++){
        if(s[i]!=c[0])
            continue;
        else
        {
            ll k=0,kk;
            for(ll j=i;j<ls;j++)
            {
                if(s[j] == c[k]){
                    k++;
                    if(k==lc){
                        kk = j;
                        break;
                    }
                }
            }
            if(k==lc){
                f[ct][0] = i;
                f[ct][1] = kk;
                ct++;
            }
        }
    }
}
int main()
{
    string a,b,c;
    ll t;
    cin>>t;
    for(ll cs =1; cs<=t; cs++)
    {
        cin>>a>>b>>c;
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        memset(f1,0,sizeof(f1));
        memset(f2,0,sizeof(f2));
        cf1=cf2=0;
        lcs(a,b,dp1);
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        reverse(c.begin(),c.end());
        lcs(a,b,dp2);
        fd(a,c,f1,cf1);
        fd(b,c,f2,cf2);
        ll ans = 0;
        ll la = a.length(),lb = b.length(),lc = c.length();
        for(ll i=0;i<cf1;i++)
        {
            for(ll j=0;j<cf2;j++){
                ll x1,x2;
                if(f1[i][0]>0 && f1[j][0]>0){
                    x1 = dp2[f1[i][0]-1][f2[j][0]-1];
                }else{
                    x1 = 0;
                }
                if(f1[i][1]<la-1&&f2[j][1]<lb-1){
                    x2 = dp1[la-f1[i][1]-2][lb-f2[j][1]-2];
                }else{
                    x2 = 0;
                }
                ll tp = x1+x2;
                ans = max(tp,ans);
            }
        }
        cout<<"Case #"<<cs<<": "<<ans+lc<<endl;
    }

}
