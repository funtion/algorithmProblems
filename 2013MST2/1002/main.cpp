#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
long long n,m,a,b,p,Bcnt,Dindex,Stop,DFN[200010],LOW[200010],Stap[200010],Belong[200010],deep[200010];
bool instack[200010];
struct edge{
    edge* next;
    long long t;
};
edge es[1000010],es2[1000010];
edge* v[200010],v2[200010];
void link(long long a,long long b){
    es[++p].t = b;
    es[p].next = v[a];
    v[a] = &es[p];
}
void tarjan(long long i)
{
    long long j;
    DFN[i]=LOW[i]=++Dindex;
    instack[i]=true;
    Stap[++Stop]=i;
    for (edge *e=v[i];e;e=e->next)
    {
        j=e->t;
        if (!DFN[j])
        {
            tarjan(j);
            if (LOW[j]<LOW[i])
                LOW[i]=LOW[j];
        }
        else if (instack[j] && DFN[j]<LOW[i])
            LOW[i]=DFN[j];
    }
    if (DFN[i]==LOW[i])
    {
        Bcnt++;
        do
        {
            j=Stap[Stop--];
            instack[j]=false;
            Belong[j]=Bcnt;
        }
        while (j!=i);
    }
}
void tarjan()
{
    long long  i;
    Stop=Bcnt=Dindex=0;
    memset(DFN,0,sizeof(DFN));
    for (i=1;i<=n;i++)
        if (!DFN[i])
            tarjan(i);
}
void bfs(long long x){
    queue<long long> q;
    deep[x] = 1;
    q.push(x);
    long long temp;
    while(!q.empty()){
        temp = q.front();q.pop();
        for (edge *e=v2[temp];e;e=e->next){
            q.push(e->t);
            deep[e->t] = deep[temp]+1;
        }
    }
}
int main()
{
    while(scanf("%I64d%I64d",&n,&m),a+b!=0){
        p=0;
        memset(v,0,sizeof(v));
        while(m--){
            scanf("%I64d%I64d",&a,&b);
            link(a,b);
            link(b,a);
        }
        tarjan();
        p=0;
        memcpy(v,v2,sizeof(v));
        memset(v,0,sizeof(v));
        for(long long i=1;i<=n;i++){
            for (edge *e=v2[i];e;e=e->next){
                long long t = e->t;
                if(Belong[i] != Belong[t]){
                    link(Belong[i],Belong[t]);
                    link(Belong[t],Belong[i]);
                }
            }
        }
        memset(deep,0,sizeof(deep));
        bfs(Belong[1]);

    }
    return 0;
}
