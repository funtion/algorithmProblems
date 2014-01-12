#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
const int MAXN  = 200;
struct tree {
    int n;
    int dis[MAXN];
    std::vector<int> tr[MAXN];
    void addEdge(int a,int b){
        tr[a].push_back(b);
        tr[b].push_back(a);
    }
    void dfs(int pre,int x){
        for(int i=0;i<tr[x].size();i++){
            if(tr[x][i] != pre){
                dis[tr[x][i]] = dis[x]+1;
                dfs(x,tr[x][i]);
            }
        }
    }
    int maxlen(){
        for(int i=0;i<=n;i++)
            dis[i] = 0;
        dfs(0,1);

        int* mx = max_element(dis+1,dis+1+n);
        for(int i=0;i<=n;i++)
            dis[i] = 0;
        //cout<<mx-dis-1<<endl;
        dfs(0,mx-dis);
        mx = max_element(dis+1,dis+1+n);
        //for(int i=1;i<=n;i++)
        //    cout<<dis[i]<<' '<<endl;
        return *mx;
    }
 }trees[MAXN]; 
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,nn,a,b;
    cin>>n;
    for(int i = 0; i < n; ++i) {
        cin>>nn;
        trees[i].n = nn;
        for(int j=0;j<nn-1;j++){
            cin>>a>>b;
            trees[i].addEdge(a,b);
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=trees[i].maxlen();
    }
    cout<<ans<<endl;
    return 0;
}