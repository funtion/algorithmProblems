#include <iostream>
#include <queue>
using namespace std;
int n,m,k,s;
char mp[600][600];
bool keep[600][600],vis[600][600],inqueue[600][600];
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
void bfs(int x,int y){
    queue<int> qx,qy;
    qx.push(x);
    qy.push(y);
    int cnt = 0;
    while( !qx.empty() ) {
        int tx = qx.front();
        qx.pop();
        int ty = qy.front();
        qy.pop();
        inqueue[tx][ty]= 0;
        vis[tx][ty ] = true;
        keep[tx][ty] = true;
        cnt++;
        //cout<<tx<<' '<<ty<<' '<<cnt<<endl;
        if(cnt>=s-k)
            return;
        for(int i=0;i<4;i++){
            int xx = tx+dx[i];
            int yy = ty+dy[i];
            if(!inqueue[xx][yy]&&!vis[xx][yy]&&mp[xx][yy] !='#'){
               inqueue[xx][yy] = true;
               qx.push(xx);
               qy.push(yy);
            }
        }
    }
    //cout<<"ttt"<<x<<' '<<y<<' '<<cnt<<endl;
   
    
}
int main(){
    cin>>n>>m>>k;
    int sx=0,sy = 0;
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++ ){
            if(i==0||i==n+1||j==0||j==m+1)
                mp[i][j] = '#';
            else
                cin>>mp[i][j];
            if(mp[i][j] == '.'){
                s++;
                sx = i,sy = j;
            }

        }
    }

    bfs(sx,sy);
    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cout<<keep[i][j]<< ' ';
        cout<<endl;
    }
    */
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j] == '#')
                cout<<'#';
            else if(keep[i][j])
                cout<<'.';
            else
                cout<<'X';
        }
        cout<<endl;
    }
    return 0;
}