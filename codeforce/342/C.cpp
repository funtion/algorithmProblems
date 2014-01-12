#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
double esp = 1e-8;
int main()
{
    ll r,h;
    cin>>r>>h;
    ll ans;
    if(h%r==0)
    {
        ans = 2*(h/r)+1;
    }
    else
    {
        ans = 2*(h/r);
        ll rm = h%r;
        if(2*rm>=r)
        {
            ans+=2;
            double m = ((2+sqrt(3.0))*r)/4;
            double mm = rm;
            if(mm-m>esp)
            {
                ans++;
            }
        }else{
            ans++;
        }
    }
    cout<<ans;
}
