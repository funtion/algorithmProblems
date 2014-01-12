#include <iostream>
#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;

struct edge
{
    int v,nxt;
}e[200100];

int link1[100100],p;
int N,M;

void add(int x,int y)
{
    e[p].v=y;
    e[p].nxt=link1[x];
    link1[x]=p++;
}

int dis[100100];

void bfs(int S)
{
    memset(dis,-1,sizeof(dis));
    dis[S]=0;
    queue<int> Q;
    Q.push(S);
    while(!Q.empty())
    {
        int x=Q.front();Q.pop();
        int v;
        for(int i=link1[x];i!=-1;i=e[i].nxt)
        {
            v=e[i].v;
            if(dis[v]==-1)
            {
                dis[v]=dis[x]+1;
                Q.push(v);
            }
        }
    }
}

int main()
{
    int T,x,y;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&M);
        p=0;
        memset(link1,-1,sizeof(link1));
        for(int i=1;i<N;i++)
        {
            scanf("%d%d",&x,&y);
            add(x,y);add(y,x);
        }
        bfs(1);
        x=1;
        for(int i=1;i<=N;i++) if(dis[x]<dis[i]) x=i;
        bfs(x);
        y=0;
        for(int i=1;i<=N;i++) y=max(dis[i],y);
        while(M--)
        {
            scanf("%d",&x);
            x--;
            if(x<=y) printf("%d\n",x);
            else
            {
                printf("%d\n",x+x-y);
            }
        }
    }
    return 0;
}
