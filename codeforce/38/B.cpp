#include <iostream>
#include <cstring>
using namespace std;
int ans;
int mp[8][8],dbg[8][8];
char x;
int y;
int dx[]={-2,-2,-1,-1,1,1,2,2};
int dy[]={1,-1,2,-2,2,-2,1,-1};
inline bool ck(int x,int y){
    return 0<=x&&x<8&&0<=y&&y<8;
}
int main(){
    cin>>x>>y;
    y--;
    for(int i=0;i<8;i++){
        mp[x-'a'][i] = -1;
        mp[i][y] = -1;
    }
    mp[x-'a'][y]=1;
    cin>>x>>y;
    y--;
    for(int i=0;i<8;i++){
        if(ck(x-'a'+dx[i],y+dy[i]))
            mp[x-'a'+dx[i]][y+dy[i]] = -1;
    }
    mp[x-'a'][y] = 1;
   // memcpy(dbg ,mp,sizeof(mp));
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(mp[i][j]!=0)
                continue;
            bool flag = true;
            for(int k=0;k<8;k++){
                if(ck(i+dx[k],j+dy[k])&& mp[i+dx[k]][j+dy[k]]==1){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans++;
                dbg[i][j]=2;
            }

        }
    }
    cout<<ans<<endl;
    /*
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<dbg[i][j]<<' ';
        }
        cout<<endl;
    }
    */
}
