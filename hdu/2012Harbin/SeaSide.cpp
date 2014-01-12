#define E 400
#define V 20
typedef  int typec;
#include<queue>
#include<cstdio>
#include<cstring>
using std::priority_queue;
const typec inf = 0x3f3f3f3f; // max of cost
int n;
typec cost[E], dist[V];
int e, pnt[E], nxt[E], head[V], prev[V], vis[V];
bool sea[V];
struct qnode
{
    int v;
    typec c;
    qnode (int vv = 0, typec cc = 0) : v(vv), c(cc) {}
    bool operator < (const qnode& r) const
    {
        return c>r.c;
    }
};
void dijkstra(int n, const int src)
{
    qnode mv;
    int i, j, k, pre;
    priority_queue<qnode> que;
    vis[src] = 1;
    dist[src] = 0;
    que.push(qnode(src, 0));
    for (pre = src, i=1; i<n; i++)
    {
        for (j = head[pre]; j != -1; j = nxt[j])
        {
            k = pnt[j];
            if (vis[k] == 0 &&
                    dist[pre] + cost[j] < dist[k])
            {
                dist[k] = dist[pre] + cost[j];
                que.push(qnode(pnt[j], dist[k]));
                prev[k] = pre;
            }
        }
        while (!que.empty() && vis[que.top().v] == 1)
            que.pop();
        if (que.empty()) break;
        mv = que.top();
        que.pop();
        vis[pre = mv.v] = 1;
    }
}
inline void addedge(int u, int v, typec c)
{
    pnt[e] = v;
    cost[e] = c;
    nxt[e] = head[u];
    head[u] = e++;
}
void init()
{
    int i, u, v,w,x;
    typec c;
    e = 0;
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
    memset(prev, -1, sizeof(prev));
    memset(sea,0,sizeof(sea));
    for (i = 0; i < V; i++) dist[i] = inf;
    for (i = 0; i < n; ++i)
    {
        scanf("%d%d", &u, &v);// %d: type of cost
        if(v == 1)
            sea[i] = true;
        for(int j=0;j<u;j++){
            scanf("%d%d",&w,&x);
            addedge(i,w,x);
        }
    }
}
int main()
{

    while(scanf("%d",&n)==1){
        init();
        dijkstra(n,0);
        int ans =  inf ;
        for(int i=0;i<n;i++){
            if(sea[i] && dist[i]<ans)
                ans = dist[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
