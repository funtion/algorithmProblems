#include<cstdio>
#include<cstring>
#define MAX 200
int n,m;
int c[MAX][MAX][MAX];
inline int lowbit(int x){
    return x&(-x);
}
void update(int x,int y,int z){
    for(int i=x;i<=n;i+=lowbit(i))
        for(int j=y;j<=n;j+=lowbit(j))
            for(int k=z;k<=n;k+=lowbit(k))
                c[i][j][k]++;
}
int get(int x,int y,int z){
    int sum=0;
    for(int i=x;i>0;i-=lowbit(i))
        for(int j=y;j>0;j-=lowbit(j))
            for(int k=z;k>0;k-=lowbit(k))
                sum+=c[i][j][k];

    return sum;
}
int main(){
    while(scanf("%d%d",&n,&m)==2){
        memset(c,0,sizeof(c));
        int cmd,x1,y1,z1,x2,y2,z2;
        while(m--){
            scanf("%d",&cmd);
        if(cmd==1){
            scanf("%d%d%d",&x1,&y1,&z1);
            scanf("%d%d%d",&x2,&y2,&z2);

            update(x1,y1,z1);

            update(x1,y1,z2+1);
            update(x1,y2+1,z1);
            update(x2+1,y1,z1);

            update(x1,y2+1,z2+1);
            update(x2+1,y1,z2+1);
            update(x2+1,y2+1,z1);

            update(x2+1,y2+1,z2+1);

        }else{
            scanf("%d%d%d",&x1,&y1,&z1);
            printf("%d\n",get(x1,y1,z1)%2);
        }
        }

    }
}
