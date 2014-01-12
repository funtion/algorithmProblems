#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
template <class T>inline T GCD(T A,T B){T C;while(B!=0)C=B,B=A%B,A=C;return A;}
using namespace std;
bool mp[20][20],vis[20];
int t,n,m,cnt;

/*int x[30];
bool check(int l){
    for(int i=1;i<l;i++){
        if(GCD(x[i],x[l])!=1)
            return false;
    }
    return true;
}

int main()
{
    freopen("out.txt","w",stdout);
    for(int i=1;i<=28;i++){
        unsigned long long sum = 0;
        for(int j=1;j<=i;j++)x[j]=j;
        do{
            if(check(i))
                sum++;
        }while(next_permutation(x+1,x+i+1));
        cout<<sum<<endl;
    }
    return 0;
}
*/
void dfs(int deep,int x){
    if(deep==n){
        cnt++;
        if(cnt>m)
            cnt-=m;
        return;
    }else{
        vis[x] = true;
        for(int i=1;i<=n;i++){
            if(!vis[i] && mp[x][i]){

                dfs(deep+1,i);
            }
        }
        vis[x]=false;
    }
}
int main(){
    for(int i=1;i<=18;i++){
        for(int j=1;j<=18;j++){
            if(GCD(i,j)==1)
                mp[i][j] = true;
            else
                mp[i][j] = false;
        }
    }
    cin>>t;
    while(t--){
        cin>>n>>m;
        cnt = 0;
        for(int i=1;i<=n;i++){
            memset(vis,0,sizeof(vis));
            vis[i] = true;
            dfs(1,i);
        }
        cout<<cnt%m<<endl;
    }
}
