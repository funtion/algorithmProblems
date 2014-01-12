#include<iostream>
#include<string>

#define mm 1000000007LL
using namespace std;
string a,b;

long long ans[5010][5010];//,m,n;
int main(){
    cin>>a>>b;
    int m,n;
    m=a.length(),n=b.length();
    long long sum=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i] == b[j]){
                ++ans[i][j];
                if(i>0&&j>0)
                    ans[i][j]+=ans[i-1][j-1];
            }

            if(j>0)
              ans[i][j]+=ans[i][j-1];
            ans[i][j]%=mm;
        }
        sum+=ans[i][n-1];
        sum%=mm;
    }
    cout<<sum%mm;


}
