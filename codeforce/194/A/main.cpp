#include <iostream>
int k[105][105];
using namespace std;
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            k[i][j]=n*(i-1)+j;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int p = i+j;
            if(p>n)p-=n;
            cout<<k[j][p]<<' ';

        }
        cout<<endl;
    }
    return 0;
}
