/*
#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;
ll mol ;
ll tll(long double ld){
    return ll(ld+0.5);
}
long double p(long double x,ll n){
    if(n==0){
        return 1;
    }else if(n==1){
        return x;
    }else if(n%2==0){
        long double t = p(x,n/2);
        if(t>mol){
            t = tll(t)%mol;
        }
        return t*t;
    }else{
        long double t =p(x,n/2);
        if(t>mol){
            t = tll(t)%mol;
        }
        return tll(t*t*x)%mol;
    }
}
long double f(ll n){
    long double c = 1/sqrt(13),x1 = (3+sqrt(13))/2,x2=(3-sqrt(13))/2;
    long double res1 = c*p(x1,n),res2=c*p(x2,n);
    return res1-res2;
}

int main()
{
    ll x,r;
    while(cin>>x){
        mol = 183120;
        r = tll(f(x))%mol;
        mol =222222224;
        r = tll(f(r))%mol;
        mol = 1000000007;
        r = tll(f(r))%mol;
        cout<<r<<endl;
    }
    return 0;
}


#include<cstdio>
#define ll __int64
int mod;
struct Matrix
{
    ll m[2][2];
    void init()
    {
        m[0][0]=3;m[0][1]=1;
        m[1][0]=1;m[1][1]=0;
    }
}a;
Matrix mul(Matrix a,Matrix b)
{
    Matrix c;
    int i,j,k;
    for(i=0;i<2;i++)for(j=0;j<2;j++)
    {
        c.m[i][j]=0;
        for(k=0;k<2;k++)
            c.m[i][j]=(a.m[i][k]*b.m[k][j]%mod+c.m[i][j])%mod;
    }
    return c;
}
Matrix mpow(Matrix a,ll n)
{
    Matrix c;
    int i,j;
    for(i=0;i<2;i++)for(j=0;j<2;j++)c.m[i][j]=(i==j);
    for(;n;n>>=1)
    {
        if(n&1)c=mul(c,a);
        a=mul(a,a);
    }
    return c;
}
ll solve(ll n,ll m)
{
    a.init();
    mod=m;
    a=mpow(a,n);
    return a.m[0][1];
}
int main()
{
    ll n;
    while(~scanf("%I64d",&n))
        printf("%I64d\n",solve(solve(solve(n,183120),222222224),1000000007));
    return 0;
}
*/
#include <iostream>
using namespace std;
typedef long long  ll;
ll mol;
struct M{
    ll m[2][2];
    M operator *(const M &r)const{
        M t;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                t.m[i][j] = 0;
                for(int k=0;k<2;k++){
                    t.m[i][j] = ((m[i][k]*r.m[k][j])%mol + t.m[i][j] )%mol;
                }
            }
        }
        return t;
    }
    M operator^(const ll x) const{
        if(x==0){
            M t;
            t.m[0][0] = t.m[1][1] =1;
            t.m[0][1] = t.m[1][0] =0;
            return t;
        }
        else if(x==1){
            return *this;
        }else if(x%2 == 0){
            M t = *this ^ (x/2);
            return t*t;
        }else{
            M t = *this ^ (x/2);
            return *this*t*t;
        }
    }
}root;
ll f(ll x){
    M m = root^x;
    return m.m[0][1];
}
int main(){
    ll n,r;
    root.m[0][0]=3;
    root.m[0][1]=1;
    root.m[1][0]=1;
    root.m[1][1]=0;
    while(cin>>n){
        mol = 183120;
        r = f(n);
        mol = 222222224;
        r = f(r);
        mol = 1000000007;
        r = f(r);
        cout<<r<<endl;
    }
}
