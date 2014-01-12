#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
struct pt{
    pt(int _x,int _y){
        x=_x;
        y=_y;
    }
int x,y;
};
int n,tx,ty;
char mp[15][15];
bool atk[15][15];
vector<pt> G,R,H,C;
int main()
{
    while(cin>>n>>tx>>ty && (n+tx+ty)){
        memset(mp,0,sizeof(mp));
        memset(atk,false,sizeof(atk));
        mp[tx][ty] = 'E';
        char t;int x,y;
        for(int i=0;i<n;i++){
            cin>>t>>x>>y;
            mp[x][y] = t;
            //atk[x][y] = true;
            if(t=='G')G.push_back(pt(x,y));
            else if(t=='R')R.push_back(pt(x,y));
            else if(t=='H')H.push_back(pt(x,y));
            else C.push_back(pt(x,y));
        }
        pt p(0,0);
        while(!G.empty()){
            p = G.back();
            G.pop_back();
            int y = p.y,x=p.x;
            while(x>=1){
                x--;
                if(x<=3){
                    atk[x][y] = true;
                }
                if(mp[x][y]&&!(x==tx&&y==ty))
                    break;

            }
        }
        while(!R.empty()){
            p = R.back();
            R.pop_back();
            int y = p.y,x=p.x;
            for(int i=x-1;i>=1;i--){
                atk[i][y] = true;
                if(mp[i][y]&&!(i==tx&&y==ty))break;

            }
            for(int i=x+1;i<=10;i++){
                atk[i][y] = true;
                if(mp[i][y]&&!(i==tx&&y==ty))break;

            }
            for(int i = y-1;i>=1;i--){
                atk[x][i] = true;
                if(mp[x][i]&&!(x==tx&&i==ty))break;

            }
            for(int i = y+1;i<=10;i++){
                atk[x][i] = true;
                if(mp[x][i]&&!(x==tx&&i==ty))break;

            }
        }
        while(!H.empty()){
            p = H.back();
            H.pop_back();
            int y = p.y,x=p.x;
            if(x-1>=1&&(!mp[x-1][y])){
                if(x-2>=1&&y-1>=1)atk[x-2][y-1]=true;
                if(x-2>=1&&y+1<=10)atk[x-2][y+1]=true;
            }
            if(x+1<=10&&(!mp[x+1][y])){
                if(x+2<=10&&y-1>=1)atk[x+2][y-1]=true;
                if(x+2<=10&&y+1<=10)atk[x+2][y+1]=true;
            }
            if(y-1>=1&&(!mp[x][y-1])){
                if(y-2>=1&&x-1>=1)atk[x-1][y-2]=true;
                if(y-2>=1&&x+1<=10)atk[x+1][y-2]=true;
            }
            if(y+1<=10&&((!mp[x][y+1]))){
                if(y+2<=10&&x-1>=1)atk[x-1][y+2]=true;
                if(y+2<=10&&x+1<=10)atk[x+1][y+2]=true;
            }
        }
        while(!C.empty()){
            p = C.back();
            C.pop_back();
            int y = p.y,x=p.x;
            int cnt=0;
            for(int i=x-1;i>=1;i--){
                if(cnt>=1)
                    atk[i][y] = true;
                if(cnt>=2)
                    break;
                if(mp[i][y]&&!(i==tx&&y==ty))cnt++;


            }
            cnt=0;
            for(int i=x+1;i<=10;i++){
                if(cnt>=1)
                    atk[i][y] = true;
                if(cnt>=2)break;
                if(mp[i][y]&&!(i==tx&&y==ty))cnt++;

            }
            cnt = 0;
            for(int i = y-1;i>=1;i--){
                if(cnt>=1)
                    atk[x][i] = true;
                if(cnt>=2)break;
                if(mp[x][i]&&!(x==tx&&i==ty))cnt++;


            }
            cnt=0;
            for(int i = y+1;i<=10;i++){
                if(cnt>=1)
                    atk[x][i] = true;
                if(cnt>=2)break;
                if(mp[x][i]&&!(x==tx&&i==ty))cnt++;
            }
        }

        bool ans;
        if(tx==1){
            if(ty==4){
                ans = atk[2][4]&&atk[1][5];
            }else if(ty==5){
                ans = atk[1][4]&&atk[2][5]&&atk[1][6];
            }else{
                ans = atk[1][5]&&atk[2][6];
            }
        }else if(tx==2){
            if(ty==4){
                ans = atk[1][4]&&atk[2][5]&&atk[3][4];
            }else if(ty==5){
                ans = atk[1][5]&&atk[2][4]&&atk[2][6]&&atk[3][5];
            }else{
                ans = atk[1][6]&&atk[2][5]&&atk[3][6];
            }
        }else{
            if(ty==4){
                ans = atk[2][4]&&atk[3][5];
            }else if(ty==5){
                ans = atk[3][4]&&atk[2][5]&&atk[3][6];
            }else{
                ans = atk[3][5]&&atk[2][6];
            }
        }
        if(ans)
            cout<<"YES\n";
        else{
            cout<<"NO\n";
        }
        /*
        for(int i=1;i<=10;i++){
            for(int j=1;j<=10;j++){
                cout<<atk[i][j];
            }
            cout<<endl;
        }
        */
    }
    return 0;
}
