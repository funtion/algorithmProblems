#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
int n,m,l,r,w;
double dp[2][300];
const double esp = 1e-9;
inline double abs(double x){return x>0?x:-x;}
int v;
int main(){
    ios::sync_with_stdio(false);
    while(cin>>n>>m>>l>>r && n+m+l+r){
        fill(dp[0],dp[0]+300,0.0);
        fill(dp[1],dp[1]+300,0.0);
        dp[0][0] = 1.0;
        v=0;
        for(int i=0;i<m;i++){
            cin>>w;
            w%=n;
            for(int j=0;j<n;j++){
                if(abs(dp[v][j])>esp){
                    dp[v^1][(j+w)%n]+=dp[v][j]*0.5;
                    dp[v^1][(j-w+n)%n]+=dp[v][j]*0.5;

                }
                dp[v][j] = 0.0;
            }
            v^=1;
        }
        double ans = 0;
        for(int i=l;i<=r;i++){
            ans+=dp[v][i-1];
        }
        cout<<fixed<<setprecision(4)<<ans<<endl;
    }
}
