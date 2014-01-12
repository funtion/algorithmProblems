#pragma comment(linker,"/STACK:100000000,100000000")

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn = 100000;

struct EDGE {
    int to, next, val, id;
}edge[maxn*2+10];

int head[maxn+10], E, dp[maxn+10][4], p[maxn+10], dep[maxn+10], ee[maxn+10];
bool vis[maxn+10];

void init(int n) {
    for(int i = 1;i <= n; i++)  head[i] = -1;
    E = 0;
}

void newedge(int u, int to, int val, int id) {
    edge[E].to = to;
    edge[E].val = val;
    edge[E].id = id;
    edge[E].next = head[u];
    head[u] = E++;
}

// 求出每个节点的深度， 深度最大的肯定是某一最长路的一头
void finddep(int u, int pre ){
    dep[u] = dep[pre] + 1;
    p[u] = pre;
    for(int i = head[u];i != -1; i = edge[i].next) {
        int to = edge[i].to;
        if(to == pre)   continue;
        finddep(to, u);
    }
}

int max(int a, int b ){
    return a>b?a:b;
}
// dp[u][0]表示该节点到子树中的最长路，dp[u][1]表示次长路 ， dp[u][2]表示该节点这颗树中的最长路
void cal(int u, int pre) {
    dp[u][0] = dp[u][1] = dp[u][2] = 0;
    for(int i = head[u];i != -1;i = edge[i].next) {
        int to = edge[i].to;
        if(to == pre)   continue;
        cal(to, u);
        int now = dp[to][0] + 1;
        if(now >= dp[u][0]) {
            dp[u][1] = dp[u][0];
            dp[u][0] = now;
        }else if(now > dp[u][1])
            dp[u][1] = now;
        dp[u][2] = max(dp[u][2], dp[to][2]);
    }
    dp[u][2] = max(dp[u][2] , dp[u][1] + dp[u][0]);
//    printf("%d %d\n", u, dp[u][2]);
}

int mxlen; // 整棵树求出的最长路

void dfs(int u, int pre) {
    for(int i = head[u];i != -1;i = edge[i].next) {
        int to = edge[i].to;
        int val = edge[i].val;
        int id = edge[i].id;
        if(to == pre)   continue;
        dfs(to, u);
        if(vis[u] && vis[to])  //边在最长路上
            ee[id] = max(ee[id], val*dp[to][2]);
        else
            ee[id] = val*mxlen;//边不在最长路上
    }
}

int main() {
    int n, i,  u, to, val;
    int t, cas = 1;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        init(n);
        for(i = 1;i <= n-1; i++) {
            scanf("%d%d%d", &u, &to, &val);
            newedge(u, to, val, i);
            newedge(to, u, val, i);
        }
        dep[0] = -1;
        finddep(1, 0);
        u = 1;
        for(i = 1;i <= n; i++) if(dep[i] > dep[u])
            u = i;
        finddep(u, 0);
        to = 1;
        for(i = 1;i <= n; i++) if(dep[i] > dep[to])
            to = i;
        // u ， to为最长路的两头
        for(i = 1;i <= n; i++)  vis[i] = 0;
        int cur = to;
        while(cur != 0) {
            vis[cur] = 1;
            cur = p[cur];
        }
        mxlen = dep[to];
        for(i = 1;i <= n-1; i++)    ee[i] = 0;
        // 双向都dfs一遍
        cal(u, -1);
        dfs(u, -1);
        cal(to, -1);
        dfs(to, -1);
        int ans = 1;
        for(i = 1;i <= n-1; i++) if(ee[i] < ee[ans])
            ans = i;
        printf("Case #%d: %d\n", cas++, ans);
    }
    return 0;
}
