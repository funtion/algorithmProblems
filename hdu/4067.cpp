#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;
int n,m,deep[100100];
vector<int> mp[100100];
int dfs(int x,int fa,int dep){
    deep[x] = dep;
    int mx = deep[x];
    int sz = mp[x].size();
    for(int i=0;i<sz;++i){
        if(mp[x][i]!=fa){
            int dd = dfs(mp[x][i],x,dep+1);
            if(dd>mx){
                mx = dd;
                //uu = mp[x][i];
            }

        }
    }
    return mx;
}
int main(){
    //ios::sync_with_stdio(false);
    int t;
    scanf("%d",&t);//cin>>t;
    while(t--){
        scanf("%d%d",&n,&m);//cin>>n>>m;
        for(int i=00;i<=n;i++)
            mp[i].clear();
        int u,v;
        for(int i=0;i<n-1;i++){
            scanf("%d%d",&u,&v);//cin>>u>>v;
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        dfs(1,-1,1);
        int uu,mx=0;
        for(int i=1;i<=n;i++){
            if(deep[i]>mx){
                mx = deep[i];
                uu = i;
            }
        }
        //cout<<"mx"<<mx<<"uu"<<uu<<endl;
        int k = dfs(uu,-1,1);
        //cout<<"k"<<k<<endl;
        //k++;
        int query;
        while(m--){
            scanf("%d",&query);//cin>>query;
            if(query<=k){
                printf("%d\n",query-1);//cout<<query-1<<endl;
            }else{
                printf("%d\n",k-1+2*(query-k));//cout<<k-1+2*(query-k)<<endl;
            }
        }
    }
}
