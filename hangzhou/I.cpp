#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdio>
using namespace std;
int inline  abs(int x)
{
    return x>0?x:-x;
}
struct pt
{
    int x,y;
    int dis(const pt& r)const
    {
        return abs(x-r.x)+abs(y-r.y);
    }
} h[2000],c[2000]; //,ansh,ansc;
char mp[50][50];
int m,n;
int main()
{
    while(scanf("%d%d",&m,&n)==2)
    {
        if(m==0&&n==0) break;
        int ch=0,cc=0;
        for(int i=0; i<m; i++)
        {
            scanf("%s",mp[i]);
            for(int j=0; j<n; j++)
            {
                if(mp[i][j] == 'C')
                {
                    c[cc].x = i;
                    c[cc].y = j;
                    cc++;
                }
                else if(mp[i][j] == 'H')
                {
                    h[ch].x = i;
                    h[ch].y = j;
                    ch++;
                }
            }
        }
        int ans = 100000000;
        int ansh=0,ansc = 0;
        for(int i=0; i<ch; i++)
        {
            for(int j=0; j<cc; j++)
            {
                if( h[i].dis(c[j])<ans )
                {
                    ans = h[i].dis(c[j]);
                    ansh = i;
                    ansc = j;

                }
            }
        }
        printf("%d %d %d %d\n",h[ansh].x,h[ansh].y,c[ansc].x,c[ansc].y);
    }
    return 0;
}
