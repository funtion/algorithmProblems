#include <iostream>
using namespace std;
int n,dp[55];
char s[55];
int main(){
    cin>>n>>s;
    fill(dp,dp+55,0);
    for(int i=1;i<n;i++){
        int b = 1;
        while(i-b>=0 &&s[i-b]==s[i])b++;
        dp[i] = min(dp[i-1]+1,dp[i-b]+b-1);
    }
    cout<<dp[n-1]<<endl;
}
