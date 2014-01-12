#include<cstdio>
#include<queue>
#include<algorithm>
#define INF (0x3f3f3f3f)
using namespace std;
bool mp[200][200];
int dis[10][200][200];
const int dx[]={-1,0,1,0},dy[]={0,-1,0,1};
typedef pair<int,int> pii;
pii start,key[5];
int m,n,k;
inline bool va(int x,int y){
    return (x>=0&&x<n&&y>=0&&y<m);
}
void bfs(pii root,int di[200][200]){
    bool vis[200][200];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            vis[i][j] = false;
            di[i][j] = INF;
        }

    queue<pii> qu;
    qu.push(root);
    di[root.first][root.second] = 0;
    vis[root.first][root.second] = true;
    while(!qu.empty()){
        pii t = qu.front();
        qu.pop();
        for(int i=0;i<4;i++){
            if(va(t.first+dx[i],t.second+dy[i])&& mp[t.first+dx[i]][t.second+dy[i]] &&!vis[t.first+dx[i]][t.second+dy[i]]){
                di[t.first+dx[i]][t.second+dy[i]] = di[t.first][t.second]+1;
                vis[t.first+dx[i]][t.second+dy[i]] = true;
                qu.push(make_pair(t.first+dx[i],t.second+dy[i]));
            }
        }
    }
}
int main(){

    char x;
    while(scanf("%d%d",&n,&m)==2&&m+n){
        for(int i=0;i<n;i++){
            scanf("%c",&x);
            for(int j=0;j<m;j++)
            {
                scanf("%c",&x);
                if(x == '#')
                    mp[i][j] = false;
                else{
                    mp[i][j] = true;
                    if( x == '@'){
                        start.first = i;
                        start.second = j;
                    }
                }
            }
        }
        scanf("%d",&k);
        for(int i=0;i<k;i++){
            scanf("%d%d",&key[i].first,&key[i].second);
            key[i].first--;
            key[i].second--;
        }
        bfs(start,dis[0]);
        bool ok = true;
        for(int i=0;i<k;i++){
            if(dis[0][key[i].first][key[i].second] == INF)
                ok = false;
        }
        if(!ok){
            puts("-1");
            continue;
        }
        for(int i=0;i<k;i++){
            bfs(key[i],dis[i+1]);
        }

        int *pe = new int[k+1];
        for(int i=0;i<=k;i++)pe[i] = i;
        int ans = INF;
        do{
            int tp = 0;
            for(int i=1;i<=k;i++){
                int it = pe[i]-1;
                tp+=dis[pe[i-1]][key[it].first][key[it].second];//printf("tp = %d\n",tp);
            }

            if(tp<ans)
                ans = tp;
        }while(next_permutation(pe+1,pe+k+1));
        printf("%d\n",ans);
    }
}
