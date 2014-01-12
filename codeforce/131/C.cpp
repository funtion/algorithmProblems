#include <iostream>
using namespace std;
typedef long long ll;
ll c[61][61],ans;
int m,n,t;

int main(){
    cin>>n>>m>>t;
    int si = max(4,t-m);
    int ei = min(n,t-1);
    for(int i=0;i<=60;i++)c[i][0]=1;
    for(int i=0;i<=60;i++)c[0][i]=1;
    for(int i=1;i<=60;i++){
        for(int j=1;j<=i;j++){
            c[i][j] = c[i][j-1]*(i-j+1)/j;
        }
    }
    for(int i=si;i<=ei;i++){
        ll tt = c[n][i]*c[m][t-i];
        ans+=tt;
    }
    cout<<ans;
}
