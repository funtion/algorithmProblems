#include <iostream>
#include <queue>
using namespace std;
int mp[10][10],mm[10][10],md[10][10];
void dfs(int x,int y ,int t){
    mp[x][y] = t;
    if(x-2>=1&&y-2>=1&&mp[x-2][y-2] == -1)
        dfs(x-2,y-2,t);
    if(x-2>=1&&y+2<=8&&mp[x-2][y+2] == -1)
        dfs(x-2,y+2,t);
    if(x+2<=8&&y-2>=1&&mp[x+2][y-2] == -1)
        dfs(x+2,y-2,t);
    if(x+2<=8&&y+2<=8&&mp[x+2][y+2] == -1)
        dfs(x+2,y+2,t);
}
void bfs(int a,int b){
    for(int i=1;i<=8;i++)
        for(int j=1;j<=8;j++)
    md[i][j] = -1;
    md[a][b] = 0;
    queue<int> qx,qy;
    qx.push(a);
    qy.push(b);
    while(!qx.empty()){
        int x,y;
        x = qx.front();y=qy.front();
        qx.pop();qy.pop();
         if(x-2>=1&&y-2>=1&&md[x-2][y-2] == -1)
        {
                md[x-2][y-2] = md[x][y]+1;
                qx.push(x-2);
                qy.push(y-2);
        }
        if(x-2>=1&&y+2<=8&&md[x-2][y+2] == -1)
            {
                md[x-2][y+2] = md[x][y]+1;
                qx.push(x-2);
                qy.push(y+2);
        }
        if(x+2<=8&&y-2>=1&&md[x+2][y-2] == -1)
           {
                md[x+2][y-2] = md[x][y]+1;
                qx.push(x+2);
                qy.push(y-2);
        }
        if(x+2<=8&&y+2<=8&&md[x+2][y+2] == -1)
           {
                md[x+2][y+2] = md[x][y]+1;
                qx.push(x+2);
                qy.push(y+2);
        }
    }
}
int x1,x2,y1,y2;
int main()
{
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++)
            mp[i][j] = -1;
    }
    int t=0;
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            if(mp[i][j] == -1 )
                dfs(i,j,t++);
        }
    }
    cin>>t;
    for(int i=0;i<8;i++)
    {

        for(int j=0;j<8;j++)
            cout<<i%4*4+j%4<<" ";
        cout<<endl;
    }
    char x;
    while(t--){
        x1 = -1;
        for(int i=1;i<=8;i++){
            for(int j=1;j<=8;j++){
                cin>>x;
                if(x=='.')
                    mm[i][j] = 0;
                else if(x=='#')
                    mm[i][j] = 1;
                else{
                    mm[i][j] = 0;
                    if(x1==-1){
                        x1 = i;
                        y1 = j;
                    }else{
                        x2 = i;
                        y2 = j;
                    }
                }
            }

        }
        //cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<mp[x1][y1]<<mp[x2][y2];
        if(mp[x1][y1] != mp[x2][y2]){
                cout<<"NO\n";
            }else{
                bfs(x1,y1);
                if(md[x2][y2]%2 == 0){
                    cout<<"YES\n";
                }else{
                    cout<<"NO\n";
                }
            }

    }

    return 0;
}
