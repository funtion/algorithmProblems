#include <iostream>
#include <cstring>
using namespace std;
int n;
int main()
{
    bool a[200];
    int x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        a[i] = (x==1)?true:false;
    }
    int b[2][200],s=0;
    for(int i=0;i<n;i++){
        if(a[i])
            s++;
        b[0][i] = s;
    }
    s = 0;
    for(int i=n-1;i>=0;i--){
        if(a[i])
            s++;
        b[1][i] = s;
    }
    int ma = 0;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            if( a[j] == false){
                sum++;
            }
            if(i == 0){
                if( j == n -1 ){
                    if(sum > ma){
                        ma = sum;
                    }
                }else{
                    if(sum + b[1][j+1] >ma )
                        ma = sum + b[1][j+1];
                }
            }else{
                if(j == n-1){
                    if(sum + b[0][i-1] > ma){
                            ma = sum + b[0][i-1];
                    }
                }else{
                    if(sum + b[0][i-1]+b[1][j+1] > ma)
                        ma = sum + b[0][i-1]+b[1][j+1];
                }
            }
        }
    }
    cout<<ma;
    return 0;
}
