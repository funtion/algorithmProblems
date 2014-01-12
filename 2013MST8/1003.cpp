#include <cstdio>
#include <cstring>
#include <queue>
struct pt
{
    int x,y;
    pt(int _x,int _y):x(_x),y(_y) {}
};
int mp[1100][1100];
bool used[1100][1100];
int n,m,k,t;
inline bool ck(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<m)
    {
        return mp[x][y]!=-1;
    }
    return false;
}
inline bool ck2(int x,int y){
    return !used[x][y] && ck(x,y);
}
void add(int x,int y)
{
    mp[x][y] = -1;
    used[x][y] = true;

    if(ck(x-1,y-1)) mp[x-1][y-1]++;
    if(ck(x-1,y))   mp[x-1][y]++;
    if(ck(x-1,y+1)) mp[x-1][y+1]++;
    if(ck(x,y-1))   mp[x][y-1]++;
    if(ck(x,y+1))   mp[x][y+1]++;
    if(ck(x+1,y-1)) mp[x+1][y-1]++;
    if(ck(x+1,y))   mp[x+1][y]++;
    if(ck(x+1,y+1)) mp[x+1][y+1]++;
}
pt fd()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(!used[i][j])
                return pt(i,j);
        }
    }
    return pt(-2,-2);
}
int calc()
{
    int ans=0,rem=n*m-k;
    std::queue<pt> qu;
    while(rem)
    {
        pt h = fd();
        if(h.x == -2)
            break;
        qu.push(h);
        while(!qu.empty())
        {
            pt xx = qu.front();
            qu.pop();
            rem--;
            used[xx.x][xx.y] = true;
            if(mp[xx.x][xx.y]==0)
            {
                if(ck2(xx.x-1,xx.y-1))  qu.push(pt(xx.x-1,xx.y-1));
                if(ck2(xx.x-1,xx.y))    qu.push(pt(xx.x-1,xx.y));
                if(ck2(xx.x-1,xx.y+1))  qu.push(pt(xx.x-1,xx.y+1));
                if(ck2(xx.x,xx.y-1))     qu.push(pt(xx.x,xx.y-1));
                if(ck2(xx.x,xx.y+1))     qu.push(pt(xx.x,xx.y+1));
                if(ck2(xx.x+1,xx.y-1))   qu.push(pt(xx.x+1,xx.y-1));
                if(ck2(xx.x+1,xx.y))     qu.push(pt(xx.x+1,xx.y));
                if(ck2(xx.x+1,xx.y+1))   qu.push(pt(xx.x+1,xx.y+1));
            }
        }
        ans++;
    }
    return ans;
}
int main()
{
    scanf("%d",&t);
    int cas=0;
    while(cas++<t)
    {
        memset(mp,0,sizeof(mp));
        memset(used,0,sizeof(used));
        scanf("%d%d%d",&n,&m,&k);
        int x,y;
        for(int i=0; i<k; i++)
        {
            scanf("%d%d",&x,&y);
            add(x,y);
        }
        int ans = calc();
        if(ans%2==0){
            printf("Case #%d: Fanglaoshi\n",cas);
        }
        else{
            printf("Case #%d: Xiemao\n",cas);
        }
    }
}
