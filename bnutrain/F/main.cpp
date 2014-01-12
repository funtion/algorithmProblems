#include <iostream>
#include <cstdio>
typedef long long ll;
using namespace std;
int T;
ll N,ns[50010];
void out(ll x)
{
    ll v = ns[x],mxl = -1,mxr=-1;
    ll mxll=0,mxrl=0;

    for(ll i = x-1; i>=0; i--)
    {
        if(ns[i] < v)
        {
            if(ns[i] >mxl)
            {
                mxl = ns[i];
                mxll = i;
            }
        }
        else
            break;
    }
    for(ll i=x+1; i<N; i++)
    {
        if(ns[i] < v)
        {
            if(ns[i] > mxr)
            {
                mxr = ns[i];
                mxrl = i;
            }
        }
        else
            break;
    }
    if(mxll)
        mxll++;
    if(mxrl)
        mxrl++;
    printf("%I64d %I64d",mxll,mxrl);
}
int main()
{
    scanf("%d",&T);
    for(int i=0; i<T; i++)
    {
        scanf("%I64d",&N);
        for(ll j=0; j<N; j++)
        {
            scanf("%I64d",&ns[j]);
        }
        printf("Case %d:\n",i+1);
        for(ll i=0; i<N; i++)
        {
            out(i);
        }
    }
    return 0;
}
