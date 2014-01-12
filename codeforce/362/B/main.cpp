#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
    int n,m;
    cin>>n>>m;
    ll x[4000];
    for(int i=0;i<m;i++)
        cin>>x[i];
    bool o = true;
    for(int i=0;i<m;i++){
        if(x[i] == 1 || x[i] == n)
        {
            o = false;
            break;
        }
    }
    if(!o){
        cout<<"NO";
    }else{
        sort(x,x+m);
        for(int i=0;i+2<m&&x[i+2]<=n;i++){
            if( x[i+1] == x[i]+1 && x[i+2] == x[i+1]+1){
                o = false;
                break;
            }
        }
        if(o){
            cout<<"YES";
        }else{

        cout<<"NO";
        }
    }
    return 0;
}
