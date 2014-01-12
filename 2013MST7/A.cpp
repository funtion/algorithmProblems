#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
int q,k,op,r;
using namespace std;
typedef long  ll;
ll part[60001][15];
bool del[60010];
struct tt{
    int x,y;
    ll di;
    tt(int _x,int  _y,ll _z):x(_x),y(_y),di(_z){}
    bool operator <(const tt &r)const{
    return di<r.di;
    }
};
inline ll dis(int a,int b)
{
    ll ans = 0;
    for(int i=0; i<k; i++){
         ans+=abs(part[a][i]-part[b][i]);
    }
    return ans;
}
int main()
{
    while(scanf("%d%d",&q,&k)==2)
    {
        priority_queue<tt> qt;
        fill(del,del+q+5,true);
        for(int i=1; i<=q; i++)
        {

            scanf("%d",&op);
            if(op==0)
            {
                del[i] = false;
                for(int j=0; j<k; j++)
                {
                    scanf("%ld",&part[i][j]);
                }
                for(int j=1; j<=i; j++)
                {
                    if(!del[j]){
                        ll temp  = dis(i,j);
                        qt.push(tt(i,j,temp));
                    }
                }
                printf("%ld\n",qt.top().di);

            }
            else
            {
                scanf("%d",&r);
                del[r] = true;
                tt te(0,0,0);
                while(te=qt.top(),del[te.x]||del[te.y]){
                    qt.pop();
                }
                printf("%ld\n",qt.top().di);
            }
        }
    }
}

