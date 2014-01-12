#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n,t,u,v,m,a;
    long long b;
    char cmd;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        printf("Case #%d:\n",i);
        scanf("%d",&n);
        int fa[50001];
        for(int j=0;j<=50000;j++){
            fa[j] = j;
        }
        for(int j=1;j<n;j++){
            scanf("%d %d",&u,&v);
            fa[u] = v;
        }
        scanf("%d",&m);
        int time[50001];
        long long task[50001];
        memset(task,-1,sizeof(task));
        memset(time,-1,sizeof(time));
        int t=0;
        while(m--){
            scanf("%c",&cmd);
            scanf("%c",&cmd);
            if(cmd == 'C'){
                scanf("%d",&a);
                int ti=-1;
                long long ta=-1;
                while(fa[a]!=a){
                    if(time[a] > ti){
                        ti = time[a];
                        ta = task[a];
                    }
                    a =fa[a];
                }
                if(time[a] > ti){
                    ti = time[a];
                    ta = task[a];
                }
                printf("%d\n",ta);
            }else{
                scanf("%d %lld",&a,&b);
                task[a] = b;
                time[a] = t++;
            }
        }
    }
    return 0;
}
