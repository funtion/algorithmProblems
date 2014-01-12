#include <iostream>
#include <cstdio>
typedef unsigned long long ll;
using namespace std;

ll n;

ll pow(const ll x,int t){
    if(t==0)
        return 1;
    if(t==1)
        return x;
    ll temp = pow(x,t/2);
    if(t%2 == 0)
        return temp*temp;
    else
        return temp*temp*x;
}
inline ll f1(int r,ll k){
    return (pow(k,r+1)-1)/(k-1);
}
inline ll f2(int r,ll k){
    return k*(pow(k,r)-1)/(k-1);
}
ll gk1(int r){
    ll l=2,h = n/r,m;
    while(h>=l){
        m = (l+h)/2;
        ll res = f1(r,m);
        if( res == n){
            return m;
        }else if(res > n){
            h = m-1;
        }else{
            l = m+1;
        }
    }
    return -1;
}
ll gk2(int r){
    ll l=2,h = n/r,m;
    while(h>=l){
        m = (l+h)/2;
        ll res = f2(r,m);
        if( res == n){
            return m;
        }else if(res > n){
            h = m-1;
        }else{
            l = m+1;
        }
    }
    return -1;
}
int gr(){
    if(n<=8)
        return n;
    int r = 1;
    ll t = 2;
    while(t<n){
        t<<=1;
        r++;
    }
    return r;
}
int main()
{

    while(scanf("%I64d",&n)!=EOF){
            unsigned int mr = -1;
            ll k;
            ll mk = -1,mrk = -1;
            int rm  = 48;
            for(int r = rm;r>=1;r--){
                ll k1 = gk1(r),k2 = gk2(r);
                k = min(k1,k2);
                if(r*k <= mrk){
                    mr = r;
                    mk = k;
                    mrk = r*k;
                }
            }
            printf("%d %I64d\n",mr,mk);
    }
    return 0;
}
