#include<iostream>
#include<algorithm>
#define N 15
#define M 1000000007
using namespace std;
long long  dp[1010][1010];
void init(){
    for(int i=1;i<=1000;i++){
        dp[i][0] = dp[i][i-1] = 1;
        for(int j=1;j<i-1;j++){
            if(j<=(i-1)/2){
                dp[i][j] = ((dp[i-1][j]*(j+1))%M+(dp[i-1][j-1]*(i-j))%M)%M;
                dp[i][j] = (dp[i][j]+ M)%M;
            }else{
                dp[i][j] = dp[i][i-1-j];
            }

        }
    }
}
int main(){
    /*
    for(int i=0;i<N;i++){
        int a[N],b[N];
        for(int j=0;j<i;j++){
            a[j] = j;
            b[j] = 0;
        }
        do{
            int t = 0;
            for(int j=0;j<i;j++){
                if(a[j]>j)t++;
            }
            b[t]++;
        }while(next_permutation(a,a+i));
        cout<<endl<<i<<endl;
        for(int j=0;j<i;j++){
            cout<<j<<' '<<b[j]<<endl;
        }
    }
    */
    init();
    /*
    for(int i=1;i<=12;i++){
        cout<<i<<": ";
        for(int j=0;j<i;j++){
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }
    */

    int n,k;
    while(cin>>n>>k){
        cout<<dp[n][k]<<endl;
    }

    return 0;
}
