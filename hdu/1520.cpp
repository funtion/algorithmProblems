#pragma GCC optimize (2)
#include<iostream>
#include <cstring>
#define MAX 20000
using namespace std;
struct node{
    int v;
    node* next;
}*head[MAX],tree[MAX];
int n,rat[MAX],ptr;
int dp[MAX][2];//1 has
bool vis[MAX];
void init()
{
    ptr = 1;
    memset(vis,false,sizeof(vis));
    memset(dp,0,sizeof(dp));
    memset(head,0,sizeof(head));
}
void add(int x,int y)
{
    tree[ptr].v = y;
    tree[ptr].next = head[x];
    head[x] = &tree[ptr++];
}
void dfs(int x)
{
    if(vis[x])
        return;
    vis[x] = true;
    node*p = head[x];
    while(p!=NULL)
    {
        if(!vis[p->v])
        {
            dfs(p->v);
            dp[x][1]+=dp[p->v][0];
            dp[x][0]+=max(dp[p->v][0],dp[p->v][1]);
        }
        p = p->next;
    }
    dp[x][1]+=rat[x];
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        init();
        for(int i=1; i<=n; i++)
        {
            cin>>rat[i];
        }
        int p,q;

        while(cin>>p>>q&&p+q)
        {
            add(p,q);
            add(q,p);
        }
        dfs(1);
        cout<<max(dp[1][0],dp[1][1])<<endl;
    }

}
