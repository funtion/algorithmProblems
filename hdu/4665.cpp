#include <iostream>
using namespace std;
int n,a[2010],ans[2010];
bool dfs(int x,int y,int t){
    if(t==n)
        return true;
    if(x>n||y>n)
        return false;
    while(x<=n&&ans[x]!=-1){
        x++;
    }
    if(x>n)
        return false;
    for(;y<=n;y++){
        if(y>x&&ans[y] == -1&& a[x]==a[y]){
            ans[x]=0;
            ans[y]=1;
            if(dfs(x+1,y+1,t+2))
                return true;
            ans[x] = ans[y] = -1;

        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 1;i<=n;i++){
            cin>>a[i];
        }
        fill(ans,ans+n+1,-1);
        dfs(1,2,0);
        for(int i=1;i<=n;i++){
            cout<<ans[i];
        }
        cout<<endl;
    }
}
