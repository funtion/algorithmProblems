#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX_STEP 20
using namespace std;
int m,n;
char mp[300][300];
int removed[300][300];
bool vis[300][300][4];
int sx,sy,ex,ey;
int ts;
int ans;
void $(int x,int y,int dir,int k,int deep)
{
    if(deep > ans || vis[x][y][dir])
        return;
    vis[x][y][dir] = true;
    if(mp[x][y] == 'K'){
        if(removed[x][y])
        k--;
        removed[x][y] ++;
    }

    if(x==ex && y==ey && k == ts)
    {
        ans = min(ans,deep);
        //return;
    }
    else
    {
        if(mp[x][y]!='.')
        {
            switch (mp[x][y])
            {
            case 'U':
                dir = 0;
                break;
            case 'R':
                dir = 1;
                break;
            case 'D':
                dir = 2;
                break;
            case 'L':
                dir = 3;
                break;
            }
        }
        switch (dir)
        {
        case 0://up
            if(y-1<0)
                return;
            else if(mp[x][y-1]!='#')
            {
                while(y-2>=0 && mp[x][y-2] == '.'){
                   // vis[x][y-1][0] = true;
                    y--;
                }
                if(mp[x][y-1] == 'K' )
                    $(x,y-1,dir,k+1,deep);
                else
                    $(x,y-1,dir,k,deep);
            }
            else
            {
                if(x-1>0 && mp[x-1][y] !='#')
                {
                    if(mp[x-1][y] == 'K' )
                        $(x-1,y,3,k+1,deep+1);
                    else
                        $(x-1,y,3,k,deep+1);
                }
                if(x+1<m && mp[x+1][y] !='#')
                {
                    if(mp[x+1][y] == 'K' )
                        $(x+1,y,1,k+1,deep+1);
                    else
                        $(x+1,y,1,k,deep+1);
                }
                if(y+1<n && mp[x][y+1] !='#')
                {
                    if(mp[x][y+1] == 'K'  )
                        $(x,y+1,2,k+1,deep+1);
                    else
                        $(x,y+1,2,k,deep+1);
                }
            }
            break;

        case 1://right
            if(x+1>=n)
                return;
            else if(mp[x+1][y]!='#')
            {
                while(x+2<n &&mp[x+2][y]=='.'){
                    //vis[x+1][y][1] = true;
                    x++;
                }
                if(mp[x+1][y] == 'K'  )
                    $(x+1,y,dir,k+1,deep);
                else
                    $(x+1,y,dir,k,deep);
            }
            else
            {
                if(x-1>0 && mp[x-1][y] !='#')
                {
                    if(mp[x-1][y] == 'K' )
                        $(x-1,y,3,k+1,deep+1);
                    else
                        $(x-1,y,3,k,deep+1);
                }
                if(y-1>0 && mp[x][y-1] !='#')
                {
                    if(mp[x][y-1] == 'K' )
                        $(x,y-1,0,k+1,deep+1);
                    else
                        $(x,y-1,0,k,deep+1);
                }
                if(y+1<n && mp[x][y+1] !='#')
                {
                    if(mp[x][y+1] == 'K' )
                        $(x,y+1,2,k+1,deep+1);
                    else
                        $(x,y+1,2,k,deep+1);
                }
            }
            break;
        case 2://down
            if(y+1>=m)
                return;
            else if(mp[x][y+1]!='#')
            {
                while(y+2<m && mp[x][y+2] == '.'){
                    //vis[x][y+1][2]=true;
                    y++;
                }
                if(mp[x][y+1] == 'K')
                    $(x,y+1,dir,k+1,deep);
                else
                    $(x,y+1,dir,k,deep);
            }
            else
            {
                if(x-1>0 && mp[x-1][y] !='#')
                {
                    if(mp[x-1][y] == 'K')
                        $(x-1,y,3,k+1,deep+1);
                    else
                        $(x-1,y,3,k,deep+1);
                }
                if(x+1<m && mp[x+1][y] !='#')
                {
                    if(mp[x+1][y] == 'K')
                        $(x+1,y,1,k+1,deep+1);
                    else
                        $(x+1,y,1,k,deep+1);
                }
                if(y-1>0 && mp[x][y-1] !='#')
                {
                    if(mp[x][y-1] == 'K')
                        $(x,y-1,0,k+1,deep+1);
                    else
                        $(x,y-1,0,k,deep+1);
                }
            }
            break;

        case 3://left
            if(x-1<0)
                return;
            else if(mp[x-1][y]!='#')
            {
                while(x-2>=0 && mp[x-2][y]=='.'){
                    x--;
                }
                if(mp[x-1][y] == 'K')
                    $(x-1,y,dir,k+1,deep);
                else
                    $(x-1,y,dir,k,deep);
            }
            else
            {
                if(x+1<m && mp[x+1][y] !='#')
                {
                    if(mp[x+1][y] == 'K')
                        $(x+1,y,1,k+1,deep+1);
                    else
                        $(x+1,y,1,k,deep+1);
                }
                if(y-1>0 && mp[x][y-1] !='#')
                {
                    if(mp[x][y-1] == 'K')
                        $(x,y-1,0,k+1,deep+1);
                    else
                        $(x,y-1,0,k,deep+1);
                }
                if(y+1<n && mp[x][y+1] !='#')
                {
                    if(mp[x][y+1] == 'K')
                        $(x,y+1,2,k+1,deep+1);
                    else
                        $(x,y+1,2,k,deep+1);
                }
            }
            break;

        }
    }
    removed[x][y] --;
    vis[x][y][dir] = false;
}
int main()
{
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        char in;
        ts = 0,ans = MAX_STEP;
        memset(removed,0,sizeof(removed));
        memset(vis,0,sizeof(vis));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%c",&in);
                while(in=='\n')
                    scanf("%c",&in);
                //mp[i][j] = in;
                mp[j][i] = in;
                switch (in)
                {
                case 'E':
                    ex = j;
                    ey=i;
                    break;
                case 'S':
                    sx = j;
                    sy=i;
                    break;
                case 'K':
                    ts++;
                    break;
                }
            }
        }
        $(sx,sy,0,0,1);
        $(sx,sy,1,0,1);
        $(sx,sy,2,0,1);
        $(sx,sy,3,0,1);
        if(ans == MAX_STEP )ans = -1;
        printf("%d\n",ans);
    }
    return 0;
}
