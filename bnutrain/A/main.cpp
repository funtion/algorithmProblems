
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
struct pt
{
    int x,y;
    bool rmd;
} ps[60];
struct eg
{
    int a,b;
    double r;
    inline bool operator<(const eg & rr) const
    {
        return r<rr.r;
    }

} egs[4000];
using namespace std;
int T;
int n,cnt;
int F[4000];
double sum,mx;
int f(int x)
{
    if(F[x] == x)
        return x;
    else
    {
        F[x] = f(F[x]);
        return F[x];
    }
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&ps[i].x,&ps[i].y);
            ps[i].rmd =false;
        }
        int k =0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                egs[k].a = i;
                egs[k].b = j;
                egs[k].r = sqrt( ((double)ps[i].x - ps[j].x)*(ps[i].x - ps[j].x)+(ps[i].y - ps[j].y)*(ps[i].y - ps[j].y));
                ++k;
            }
        }
        sort(egs,egs+k);
        mx = 9e99;
        for(int i=0; i<n; i++)
        {
            ps[i].rmd = true;
            for(int j=0; j<n; j++)
            {
                F[j] = j;
            }
            sum =  0;
            cnt = 0;
            for(int j=0; j<k; j++)
            {
                if(ps[egs[j].a].rmd || ps[egs[j].b].rmd)
                    continue;
                int fa = f(egs[j].a);
                int fb = f(egs[j].b);
                if(fa != fb)
                {
                    sum += egs[j].r;
                    F[fb] = fa;
                    cnt++;
                    if(cnt == n-2)
                        break;
                }
            }

            ps[i].rmd = false;
            mx = min(mx,sum);
        }

        printf("%.2f",mx);
        if(T)
            printf("\n");
    }
    return 0;
}
