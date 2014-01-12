#include<iostream>
typedef int ll;
#define MM 401
int m[MM][MM],n;
ll dpb[MM][MM][MM];
using namespace std;
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        cin>>m[i][j];
    ll ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ll y = 0;
            /*
            for(int k=0;i+k<n&&j+k<n;k++){
                x+=m[i+k][j+k];
                dpa[i][j][k] = x;
            }
            */
            for(int k=0;i+k<n&&j-k>=0;k++){
                y+=m[i+k][j-k];
                dpb[i][j][k] = y;
            }
        }
    }
    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;i+k<n&&j+k<n;k++){
                cout<<dpa[i][j][k]<<' ';
            }
            cout<<endl;
        }
    }
    cout<<"************\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;i+k<n&&j-k>=0;k++){
                cout<<dpb[i][j][k]<<' ';
            }
            cout<<endl;
        }
    }
    */
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ll x = 0;
            for(int k=0;i+k<n&&j+k<n;k++){
                x+=m[i+k][j+k];
                if(x-dpb[i][j+k][k]>ans)
                    ans = x-dpb[i][j+k][k];
            }
        }
    }
    cout<<ans<<endl;
}
