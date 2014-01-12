#pragma comment(linker, "/STACK:16777216")
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
const int N = 100050;
typedef long long ll;
using namespace std;
ll n,deep[N],num[N],prt[N];
vector<ll> tree[N];
void init(){
    for(int i=1;i<=n;i++){
        tree[i].clear();
    }
    memset(deep,0,sizeof(deep));
    memset(num,0,sizeof(num));
    memset(prt,0,sizeof(prt));
}
void dfs(int x,int pr,int dp){
    deep[x] = dp;
    prt[x] = pr;
    int sz = tree[x].size();
    for(int i=0;i<sz;i++){
        if(tree[x][i]!=pr){
            dfs(tree[x][i],x,dp+1);
        }
    }
    int ct = 1;
    for(int i=0;i<sz;i++){
        //if(tree[x][i]!=pr){
            ct+= num[ tree[x][i]];
        //}
    }
    num[x] = ct;
}
int main(){
    //int size = 256 << 20; // 256MB
    //char *p = (char*)malloc(size) + size;
    //__asm__("movl %0, %%esp\n" :: "r"(p));


    freopen("4705.in","r",stdin);

    //freopen("4705.out","w",stdout);
    while(scanf("%I64d",&n)==1){
        init();
        int x,y;
        for(int i=0;i<n-1;i++){
            scanf("%d%d",&x,&y);
            tree[x].push_back(y);
            tree[y].push_back(x);
        }

        dfs(1,-1,1);

        /*
        for(int i=1;i<=n;i++){
            printf("%d:deep = %d, num = %d prt = %d\n",i,deep[i],num[i],prt[i]);
        }
        */

        ll cnt  = 0,ans = ((ll)n*(n-1)*(n-2))/6;
        for(int i=1;i<=n;i++){

            ll a = (n-num[i])*(num[i]-1),b=0;
            int sz = tree[i].size();
            ll s1=0,s2=0;
            for(int j=0;j<sz;j++){
                if(tree[i][j] == prt[i])
                    continue;
                s1+=num[tree[i][j]];
                s2+=(num[tree[i][j]])*(num[tree[i][j]]);
            }
            b = s1*s1-s2;
            cnt+=(a+b/2);
            //printf("%d:sz = %d,a=%I64d,b=%I64d\n",i,sz,a,b);
        }
        ans-= cnt;
        printf("%I64d\n",ans);
    }
    return 0;
}
