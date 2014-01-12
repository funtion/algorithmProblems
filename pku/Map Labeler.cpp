int n;
/******************2-SAT*********************/
#include<cstring>
#define V 1100
#define E 1001100
int top,cnt,index,ecnt;
bool instack[V];
int stack[V],id[V],dfn[V],low[V];
int head[V];
struct edge
{
    int s,t,next;
} e[E];
void addedge(int u,int v)
{
    e[ecnt].s=u;
    e[ecnt].t=v;
    e[ecnt].next=head[u];
    head[u]=ecnt++;
}
void tarjan(int u)
{
    int v;
    int tmp;
    dfn[u]=low[u]=++index;
    instack[u]=true;
    stack[++top]=u;
    for(int k=head[u]; k!=-1; k=e[k].next)
    {
        v=e[k].t;
        if(!dfn[v])
        {
            tarjan(v);
            if(low[v]<low[u])
            {
                low[u]=low[v];
            }
        }
        else if(instack[v] && dfn[v] < low[u])
        {
            low[u]=dfn[v];
        }
    }
    if(dfn[u]==low[u])
    {
        cnt++;
        do
        {
            tmp=stack[top--];
            instack[tmp]=false;
            id[tmp]=cnt;
        }
        while(tmp!=u);
    }
}
void solve()
{
    top = cnt = index = 0;
    memset(dfn,0,sizeof(dfn));
    for(int i=0; i<2*n; i++)
    {
        if(!dfn[i])
            tarjan(i);
    }
}
bool Two_Sat()
{
    solve();
    // for(int i=0;i<n*n;i++)
    //   printf("%d %d\n",i,id[i]);
    for(int i=0; i<n; i++)
    {
        if(id[i]==id[i+n])
        {
            return 0;
        }
    }
    return 1;
}
/******************2-SAT*********************/
#include<cstdio>
template<class T> inline T ab(T x){
    return x<0?-x:x;
}
struct point{int x,y;}ps[200];

bool rn(int r){
    //printf("r=%d\n",r);
    ecnt = 0;
    memset(head,-1,sizeof(head));
    for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++){
        if(ab(ps[i].x-ps[j].x)<r){
            if(ps[i].y>ps[j].y){
                if(ps[i].y-ps[j].y<r){
                   // puts("xx");
                    addedge(i,j+n);
                    addedge(i+n,j+n);
                    addedge(i+n,j);
                    addedge(j,i);
                    addedge(j,i+n);
                }else if( ps[i].y-ps[j].y<2*r){
                   // puts("xxx");
                    addedge(i+n,j+n);
                    addedge(j,i);
                }
            }else if(ps[i].y == ps[j].y){
               // puts("yy");
                addedge(i,j+n);
                addedge(j,i+n);
                addedge(i+n,j);
                addedge(j+n,i);
            }else{
                if(ps[j].y-ps[i].y<r){
                 //   puts("zz");
                    addedge(j,i+n);
                    addedge(j+n,i+n);
                    addedge(j+n,i);
                    addedge(i,j);
                    addedge(i,j+n);
                }else if( ps[j].y-ps[i].y<2*r){
                  //  puts("zzz");
                    addedge(j+n,i+n);
                    addedge(i,j);
                }
            }
        }
    }
    return Two_Sat();
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d",&ps[i].x,&ps[i].y);
        }

        int l = 0,h=30000,mid;
        while(l<=h-10){
            mid = (l+h)/2;
            if(rn(mid))
                l = mid+1;
            else
                h = mid-1;
            //printf("%d %d %d\n",l,mid,h);
        }
        while(!rn(h))
            h--;
        //int mid2 = 30000;
        //while(!rn(mid2))
       //    mid2--;
        printf("%d\n",h);
    }
}
