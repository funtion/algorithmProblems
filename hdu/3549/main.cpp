#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int t,n,m;
int r[20][20],pre[20];
bool vis[20];

int deep[20];

bool EK_bfs(int s,int t){
    queue<int> que;
    memset(pre,-1,sizeof(pre));
    memset(vis,false,sizeof(vis));
    pre[s] = s;
    vis[s] = true;
    que.push(s);

    int p;
    while(!que.empty()){
        p = que.front();
        que.pop();
        for(int i=0;i<n;++i){
            if(r[p][i]>0 && !vis[i]){
                pre[i] = p;
                vis[i] = true;
                if(i==t)
                    return true;
                que.push(i);
            }
        }
    }
    return false;
}
int EK(int s,int t){
    int maxflow = 0,d;
    while(EK_bfs(s,t)){
        d = r[pre[t]][t];
        for(int i=t;i!=s;i=pre[i]){
            d = min(d,r[pre[i]][i]);
        }
        for(int i=t;i!=s;i=pre[i]){
            r[pre[i]][i] -= d;
            r[i][pre[i]] +=d;
        }
        maxflow+=d;
    }
    return maxflow;
}
bool dinic_bfs(){
    queue<int> qu;
    memset(deep,-1,sizeof(deep));
    qu.push(0);
    deep[0] = 0;
    int p;
    while(!qu.empty()){
        p = qu.front();
        qu.pop();
        for(int i=0;i<n;++i){
            if(deep[i]<0 && r[p][i] ){
                deep[i] = deep[p]+1;
                qu.push(i);
            }
        }
    }
    if(deep[n-1]>0)
        return true;
    return false;
}
int dinic(int x,int low){
    if(x==n-1) return low;
    int a,tot=0,deleta=low;
    for(int i=0;i<n;i++){
        if(r[x][i] && deep[i] == deep[x]+1 && (a=dinic(i,min(low,r[x][i])))){
            r[x][i]-=a;
            r[i][x]+=a;
            //return a;
            tot+=a;
            deleta-=a;
            if(deleta==0)
                break;
        }
    }
    if(tot!=0)
        deep[x] = -1;
    return tot;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    int cas=0;
    while(cas++<t){
        cin>>n>>m;
        memset(r,0,sizeof(r));
        int a,b,c;
        for(int i=0;i<m;i++){
            cin>>a>>b>>c;
            r[a-1][b-1] += c;
        }
        //cout<<"Case "<<cas<<": "<<EK(0,n-1)<<endl;
        int ans=0,tans;
        while(dinic_bfs()){
            while( (tans = dinic(0,0x7ffffff) ))
                ans +=tans;
        }
        cout<<"Case "<<cas<<": "<<ans<<endl;
    }

    return 0;
}
