#include<iostream>
#include<cstring>
using namespace std;
int dp[10][3];
//dp[i][0] 不存在不吉利
//dp[i][1] 不存在且最高位为2
//dp[i][2] 存在不吉利数字
void init(){
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for(int i=1;i<=6;i++){
        dp[i][0] = dp[i-1][0]*9-dp[i-1][1];
        dp[i][1] = dp[i-1][0];
        dp[i][2] = dp[i-1][0]+dp[i-1][1]+dp[i-1][2]*10;
    }
}
int solve(int n){
    int len=0,bit[10];
    int tmp = n;
    while(n){
        bit[++len] = n%10;
        n/=10;
    }
    bit[len+1]=0;///
    int ans = 0;
    bool flag = false;
    for(int i=len;i!=0;i--){
        ans+=dp[i-1][2]*bit[i];
        if(flag){
            ans+=dp[i-1][0]*bit[i];
        }else{
            if(bit[i]>4)
                ans+=dp[i-1][0];
            if(bit[i+1]==6&&bit[i]>2)
                ans+=dp[i][1];///
            if(bit[i]>6)
                ans+=dp[i-1][1];
        }
        if(bit[i]==4||(bit[i+1]==6&&bit[i]==2))
            flag =true;
    }
    return tmp-ans;
}
int main(){
    int l,r;
    init();
    while(cin>>l>>r&&l+r){
        cout<<(solve(r+1)-solve(l))<<endl;
    }
}
