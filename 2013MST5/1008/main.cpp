#include <iostream>
#include <cstdio>
#define mx (1<<30)
using namespace std;
int n,m;
struct way
{
  long long length,cost;
  bool cnt;
} mp[110][110];

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int u,v,w;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                mp[i][j].cost = mx;
                mp[j][i].cost = mx;
                mp[i][j].length = 0;
                mp[j][i].length = 0;
                mp[i][j].cnt = false;
                mp[j][i].cnt = false;
            }

        }
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            mp[u][v].cost = w;
            mp[u][v].length = 1;
            mp[u][v].cnt = true;

        }

        for(int k=1; k<=n; k++)
        {
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                        if(i==k||k==j)continue;
                        if(mp[i][k].cnt && mp[k][j].cnt && (mp[i][k].cost+mp[k][j].cost)*mp[i][j].length < (mp[i][k].length+mp[k][j].length)*mp[i][j].cost  )
                        {
                            mp[i][j].cost = mp[i][k].cost+mp[k][j].cost;
                            mp[i][j].length = mp[i][k].length+mp[k][j].length;
                            mp[i][j].cnt=true;
                        }
                }
            }
        }
        ///
        for(int k=1; k<=n; k++)
        {
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    if(mp[k][k].length != 0)
                    {
                        if(mp[i][k].cnt && mp[k][j].cnt && mp[k][k].cost *mp[i][j].length < mp[i][j].cost){
                            mp[i][j].length =mx;
                            mp[i][j].cost = mx*mp[k][k].cost;
                        }
                    }

                }
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<n; j++)
            {
                if(mp[i][j].cnt == false)
                    printf("NO ");
                else
                    printf("%.3f ",(double)mp[i][j].cost/mp[i][j].length);
            }
            if(mp[i][n].cnt == false)
                printf("NO\n");
            else
                printf("%.3f\n",(double)mp[i][n].cost/mp[i][n].length);
        }
    }
    return 0;
}
