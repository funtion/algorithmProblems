#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;
int n,m;
bool mp[101][20010];
int l[101][20010],r[101][20010];
int main()
{
    //scanf("%d%d",&n,&m);
    //cout<<INT_MAX;
    ios::sync_with_stdio(false);
    cin>>n>>m;
    char x;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //scanf("%c",&x);
            cin>>x;
            mp[i][j] = mp[i][j+m]= (x=='1');
        }
    }

    int cnt;
    for(int i=0;i<n;i++){
        cnt = 0;
        for(int j=0;j<m;j++){
            if(mp[i][j])
            {
                cnt++;
                break;
            }
        }
        if(cnt==0)
            break;
    }
    if(cnt==0){
        cout<<"-1";
        return 0;
    }
    for(int i=0;i<n;i++){
        if(mp[i][0])
            l[i][0] = 0;
        else
            l[i][0] = 20000;
        for(int j=1;j<m+m;j++){
            if(mp[i][j])
                l[i][j] = 0;
            else
                l[i][j] = l[i][j-1]+1;
        }
    }
    for(int i=0;i<n;i++){
        if(mp[i][m-1])
            r[i][m+m-1] = 0;
        else
            r[i][m+m-1] = 20000;
        for(int j=m+m-2;j>=0;j--){
            if(mp[i][j])
                r[i][j] = 0;
            else
                r[i][j] = r[i][j+1]+1;
        }
    }
    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<m+m;j++){
            cout<<r[i][j]<<':'<<l[i][j]<<' ';
        }
        cout<<endl;
    }
    */
    int ans = INT_MAX;
    for(int i=0;i<m;i++){
        int t = 0;
        for(int j=0;j<n;j++){
            t+=min(min(l[j][i],l[j][i+m]),min(r[j][i],r[j][i+m]));
        }
        ans = min(ans,t);

    }
cout<<ans<<endl;

}
