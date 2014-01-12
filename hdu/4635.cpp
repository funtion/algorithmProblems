#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>
#include <climits>
const int N = 100003;
using namespace std;
vector<int> mp[N];
int m,n,ta,cnt;
int in[N],out[N],num[N];
bool instack[N];
int vis[N],low[N],belong[N];
stack<int> s;
void tarjan(int k){
    vis[k] = low[k] = ++ta;
    instack[k] = true;
    s.push(k);
    int sz = mp[k].size();
    for(int i=0;i<sz;i++){
        int u = mp[k][i];
        if(!vis[u]){
            tarjan(u);
            if(low[u]<low[k])
                low[k] = low[u];
        }else if(instack[u] && vis[u]<low[k]){
            low[k] = vis[u];
        }
    }
    if(low[k] == vis[k]){
        cnt++;
        int u;
        do{
            u = s.top();
            s.pop();
            instack[u] = false;
            belong[u] = cnt;
        }while(u!=k);
    }
}
void init(){
    ta = cnt =  0;
    while(!s.empty())
        s.pop();
    for(int i=0;i<=N;i++)
        mp[i].clear();
    memset(vis,0,sizeof(vis));
    memset(instack,0,sizeof(instack));
    memset(low,0,sizeof(low));
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    memset(num,0,sizeof(num));
}
int main(){
    //printf("%I64d",-((long long)1<<63)-1);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){

        scanf("%d%d",&n,&m);
        init();
        int x,y;
        for(int i=0;i<m;i++){
            scanf("%d%d",&x,&y);
            mp[x].push_back(y);
        }
        for(int i=1;i<=n;i++){
            if(vis[i] == 0){
                tarjan(i);
            }
        }
        if(cnt == 1){
            printf("Case %d: -1\n",cs);
        }else{
            //printf("cnt = %d\n",cnt);
            for(int i=1;i<=n;i++){
                num[belong[i]]++;
                int sz = mp[i].size();
                for(int j=0;j<sz;j++){
                    int k = mp[i][j];
                    if(belong[i]!=belong[k]){
                        out[belong[i]]++;
                        in[belong[k]]++;
                    }
                }
            }
            /*
            for(int i=1;i<=n;i++){
                printf("%d--%d\n",i,belong[i]);
            }
            for(int i=1;i<=cnt;i++){
                printf("%d %d %d \n",in[i],out[i],num[i]);
            }
            */
            long long mi = -((long long)1<<63)-1;
            for(int i=1;i<=cnt;i++){
                if(in[i] == 0 || out[i] == 0){
                    mi = min(mi,((long long)num[i])*(n-num[i]));
                }
            }
            //long long x = (long long)mi*(n-mi);
            long long ans = ((long long)n)*(n-1)-m-mi;
            printf("Case %d: %I64d\n",cs,ans);
        }
    }
}
