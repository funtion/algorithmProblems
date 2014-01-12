// #define ttt
#ifndef ttt
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
long long m[1200][1200];
bool g[1200][1200],instk[1200];
int dfn[1200],type[1200],stk[1200],low[1200],depth,top,id;
bool t1(){
    for(int i=0;i<n;i++)
    {
        if(m[i][i] != 0)
            return false;
    }
    return true;
}
bool t2()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(m[i][j] != m[j][i])
                return false;
        }
    }
    return true;
}
void tarjan(int i){
    dfn[i] = low[i] = ++depth;
    stk[++top] = i;
    instk[i] = true;
    for(int j=0;j<n*2;j++){
        if(g[i][j]){
            if(!dfn[j]){
                tarjan(j);
                low[i] = min(low[i],low[j]);
            }else{
                if(instk[j])
                    low[i] = min(low[i],dfn[j]);
            }
        }
    }
    if(dfn[i] == low[i]){
        id++;
        int j;
        do{
            j = stk[top--];
            type[j] = id;
            instk[j]= false;
        }while(i!=j);
    }
}
bool t3(){

    for(int i =0;i<32;i++){
        memset(g,false,sizeof(g));
        for(int j=0;j<n;j++){
            for(int k=j+1;k<n;k++){
                int t = m[j][k] &(1<<i);
                if(j%2 == 1 && k%2 == 1){//|
                    if(t!=0){
                        g[j+n][k] = true;
                        g[k+n][j] = true;
                        //g[j][j+n] = true;
                        //g[k][k+n] = true;
                    }else{
                        g[j][j+n] = true;
                        g[k][k+n] = true;
                    }
                }else if( j%2== 0 && k%2==0){//&
                    if(t!=0){
                        g[j+n][j] = true;
                        g[k+n][k] = true;
                        g[j][k] = true;
                        g[k][j] = true;
                    }else{
                        g[j][k+n]=true;
                        g[k][j+n]=true;
                    }
                }else{//^
                    if(t!=0){
                        g[j][k+n]=g[k+n][j]=true;
                        g[k][j+n]=g[k+n][j]=true;
                    }else{
                        g[j][k]=g[k][j]=true;
                        g[k+n][j+n]=g[j+n][k+n]=true;
                    }
                }
            }
        }
        fill(type,type+n*2,0);
        fill(dfn,dfn+n*2,0);
        fill(low,low+n*2,0);
        fill(stk,stk+n*2,0);
        fill(instk,instk+n*2,0);
        depth = top = id = 0;
        for (int j=0;j<n*2;j++){
            if(!dfn[j])
                tarjan(j);
        }
        for(int j=0;j<n;j++){
            if(type[j] == type[n+j])
                return false;
        }
    }
    return true;
}
int main()
{
    while( scanf("%d",&n) != EOF)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%I64d",&m[i][j]);
            }
        }
        if(t1() && t2() && t3())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
#else
#include<cstring>
#include<algorithm>
#include <cstdio>
using namespace std;

#define MAXN 1010
int n;
unsigned int b[510][510];
int m[1010][1010];
int id[1010];


int find_components(int n,int mat[][MAXN],int* id){
	int ret=0,a[MAXN],b[MAXN],c[MAXN],d[MAXN],i,j,k,t;
	for (k=0;k<n;id[k++]=0);
	for (k=0;k<n;k++)
		if (!id[k]){
			for (i=0;i<n;i++)
				a[i]=b[i]=c[i]=d[i]=0;
			a[k]=b[k]=1;
			for (t=1;t;)
				for (t=i=0;i<n;i++){
					if (a[i]&&!c[i])
						for (c[i]=t=1,j=0;j<n;j++)
							if (mat[i][j]&&!a[j])
								a[j]=1;
					if (b[i]&&!d[i])
						for (d[i]=t=1,j=0;j<n;j++)
							if (mat[j][i]&&!b[j])
								b[j]=1;
				}
			for (ret++,i=0;i<n;i++)
				if (a[i]&b[i])
					id[i]=ret;
		}
	return ret;
}

void build_map(int k)
{
    memset(m, 0, sizeof(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            if(i == j) continue;
            if(i % 2 == 1 && j % 2 == 1)
            {
                if(b[i][j] & (1<<k))
                {
                    m[i][j+n] = 1;
                    m[j][i+n] = 1;
                }
                else
                {
                    m[i+n][i] = 1;
                    m[j+n][j] = 1;
                }
            }
            else if(i % 2 == 0 && j % 2 == 0)
            {
                if(b[i][j] & (1<<k))
                {
                    m[i][i+n] = 1;
                    m[j][j+n] = 1;
                }
                else
                {
                    m[j+n][i] = 1;
                    m[i+n][j] = 1;
                }
            }
            else
            {
                if(b[i][j] & (1<<k) )
                {
                    m[i][j+n] = m[j+n][i] = 1;
                    m[j][i+n] = m[i+n][j] = 1;
                }
                else
                {
                    m[i][j] = m[j][i] = 1;
                    m[i+n][j+n] = m[j+n][i+n] = 1;
                }
            }
        }
}


void solve()
{
    for(int k = 0; k < 32; k++)
    {
        build_map(k);
        memset(id, 0, sizeof(id));
        find_components(2*n, m, id);

        for(int i = 0; i < n; i++)
            if(id[i] == id[i+n])
            {
                printf("NO\n");
                return;
            }
    }
    printf("YES\n");
}

int main()
{
	while(scanf("%d",&n) != EOF)
    {
	    int i, j;
	    memset(id, 0, sizeof(id));
	    memset(b, 0, sizeof(b));

        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                scanf("%d",&b[i][j]);

        bool flag = true;
        for(i = 0; i < n; i++)
            if(b[i][i]) { flag = false; break; }

        if(flag == false)
        {
            printf("NO\n");
            continue;
        }
        solve();
    }
	return 0;
}


#endif
