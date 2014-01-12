#include<iostream>
#include<cstring>
using namespace std;
const int MAXN = 1000;
int uN, vN; // u, v数目，要初始化！！！
bool g[MAXN][MAXN]; // g[i][j] 表示xi与yj相连
int xM[MAXN], yM[MAXN]; // 输出量
bool chk[MAXN]; // 辅助量检查某轮y[v]是否被check
bool SearchPath(int u)
{
    int v;
    for(v = 0; v < vN; v++)
        if(g[u][v] && !chk[v])
        {
            chk[v] = true;
            if(yM[v] == -1 || SearchPath(yM[v]))
            {
                yM[v] = u;
                xM[u] = v;
                return true ;
            }
        }
    return false ;
}
int MaxMatch()
{
    int u, ret = 0 ;
    memset(xM, -1, sizeof (xM));
    memset(yM, -1, sizeof (yM));
    for(u = 0; u < uN; u++)
        if(xM[u] == -1)
        {
            memset(chk, false, sizeof (chk));
            if(SearchPath(u)) ret++;
        }
    return ret;
}
int n,m;
int mp[MAXN][MAXN];
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m&&m+n)
    {
        memset(mp,-1,sizeof(mp));
        memset(g,0,sizeof(g));
        int x,y;
        for(int i=0; i<n; i++)
        {
            cin>>x>>y;
            mp[x][y] = mp[x+1][y] = i;
        }
        for(int i=0;i<m;i++){
            cin>>x>>y;
            if(mp[x][y]>=0){
                g[mp[x][y]][i] = true;
            }
            if(mp[x][y+1]>=0){
                g[mp[x][y+1]][i] = true;
            }
        }
        uN = n;
        vN = m;
        int tt = MaxMatch();
        cout<<m+n-tt<<endl;
        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<g[i][j]<<' ';
            }
            cout<<endl;
        }
        */
    }
}
