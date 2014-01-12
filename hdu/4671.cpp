#include <iostream>
#include <vector>
using namespace std;
int ans[110][110];
vector<int> loc[110];
int main()
{
    ios::sync_with_stdio(false);
    int m,n;
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;i++)
            loc[i].clear();
        int avg = m/n;
        int rm = m%n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=avg;j++)
            {
                ans[(i-1)*avg+j][1] = i;
                loc[i].push_back((i-1)*avg+j);
            }
        }
        for(int i=1;i<=rm;i++)
        {
            ans[avg*n+i][1] = i;
            loc[i].push_back(avg*n+i);
        }
        for(int i=1;i<=n;i++)
        {
            int sz = loc[i].size();
            int j = rm+1;
            if(j>n)
                j-=n;
            for(int k=0;k<sz;k++)
            {
                if(j==i)
                    j++;
                if(j>n)
                    j-=n;
                ans[loc[i][k]][2] = j;//cout<<i<<' '<<k<<' '<<loc[i][k]<<"  "<<j<<endl;
                j++;
                if(j>n)
                    j-=n;
            }
        }

        for(int i=1;i<=m;i++)
        {
            int k = 1;
            for(int j=3;j<=n;j++)
            {
                while(k==ans[i][1] || k==ans[i][2])
                {
                    k++;
                    if(k>n)
                        k-=n;
                }

                ans[i][j] = k;
                k++;
                if(k>n)
                    k-=n;
            }
        }

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout<<ans[i][j]<<' ';
            }
            cout<<endl;
        }
    }
}
