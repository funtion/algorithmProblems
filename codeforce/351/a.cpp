#include <iostream>
using namespace std;
double a[3000];
int n;
double dp[5000][3000];
int main(){
    cin>>n;
    for(int i=0;i<n*2;i++){
        cin>>a[i];
    }
    for(int i=1;i<2*n;i++){
        for(int j=0;j<=i;j++){
            dp[i][j] = min(dp[i-1][j]+(int)a[i]+1-a[i],dp[i-1][j-1]+a[i]-(int)a[i]);
        }
        dp[i][i+1] = 2;
    }
    for(int i=0;i<2*n;i++){
        for(int j=0;j<=i;j++)
            cout<<dp[i][j]<<' ';
        cout<<endl;
    }
    cout<<dp[2*n-1][n]<<endl;
    return 0;
}