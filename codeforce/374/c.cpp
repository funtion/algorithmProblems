#include <iostream>
#include <map>
using namespace std;
map<char,int> fk;

char mp[2000][2000];
int mid[2000][2000];
bool loop;
int n,m;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int cnt[1000100];
inline bool ck(int x,int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}
void s(int x,int y,int id,int type){
    cout<<"sss"<<x<<' '<<y<<endl;
    if(loop)
        return;
    int iid = fk[mp[x][y]];
    cout<<iid<<endl;
    mid[x][y] = id;
    if(type == 0){
        for(int i=0;i<4;i++){
            int xx = x+dx[i],yy = y+dy[i];
            bool reach = ck(xx,yy);
            
            if(reach&&fk[mp[xx][yy]] == (iid+1)%4){
                if(reach && mid[xx][yy] == id){
                    loop = true;cout<<"loop"<<xx<<' '<<yy<<endl;
                }
                s(xx,yy,id,1);
            }
            if(reach&&fk[mp[xx][yy]] == (iid+4-1)%4){
                if(reach && mid[xx][yy] == id){
                    loop = true;cout<<"loop"<<xx<<' '<<yy<<endl;
                }
                s(xx,yy,id,-1);
            }
        }
    }else if(type == 1){
        for(int i=0;i<4;i++){
            int xx = x+dx[i],yy = y+dy[i];
            bool reach = ck(xx,yy);
            if(reach&&fk[mp[xx][yy]] == (iid+1)%4){
                if(reach && mid[xx][yy] == id){
                    loop = true;
                    //cout<<"loop"<<x<<':'<<xx<<' '<<y<<':'<<yy<<' '<<fk[mp[xx][yy]]<<endl;
                 }
                s(xx,yy,id,1);
            }
        }
    }else{
        for(int i=0;i<4;i++){
            int xx = x+dx[i],yy = y+dy[i];
            bool reach = ck(xx,yy);
            
            if(reach&&fk[mp[xx][yy]] == (iid+4-1)%4){
                if(reach && mid[xx][yy] == id){
                    loop = true;cout<<"loop"<<xx<<' '<<yy<<endl;
                }
                s(xx,yy,id,-1);
            }
        }
    }
}
int main(){
    fk['D'] = 0;
    fk['I'] = 1;
    fk['M'] = 2;
    fk['A'] = 3;
    cin>>n>>m;
    int t = 0;
    for(int i=0;i<n;i++)cin>>mp[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mp[i][j] == 'D' && mid[i][j] == 0){
                s(i,j,++t,0);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mid[i][j]<< ' ';
        }
        cout<<endl;
    }
    if(loop){
        cout<<"Poor Dima!\n";
    }else{
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cnt[mid[i][j]]++;
            }
        }
        int ans = 0;
        for(int i=1;i<=t;i++){
            if(cnt[i]>ans)
                ans = cnt[i];
        }
        if(ans>=4){
            cout<<ans/4<<endl;
        }else{
            cout<<"Poor Dima!\n";
        }
    }
    
    return 0;
}