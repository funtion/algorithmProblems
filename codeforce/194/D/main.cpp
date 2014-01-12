#include <iostream>

using namespace std;
long long n,m;
int x,y;
bool a[1001],b[1001];
int main()
{
    cin>>n>>m;
    while(m--){
        cin>>x>>y;
        a[x] = true;
        b[y] = true;
    }
    int ans = 0;
    for(int i=2;i<n;i++){
        if(!a[i]||!b[i]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
