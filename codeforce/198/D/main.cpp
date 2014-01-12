#include <iostream>
#include <algorithm>
#define V 200101
using namespace std;
int n;
int nm[200101];
bool **g;
void st()
{
    for(int i=0; i<n; i++)
    {
        bool sp = false;
        for(int i=0; i<n-1; i++)
        {
            if(nm[i]>nm[i+1])
            {
                g[i][i+1] = false;
                sp = true;
                swap(nm[i],nm[i+1]);
            }
        }
        if(!sp)
        {
            return ;
        }
    }

}
int  dp[V], **stk, mx;
int dfs(int n, int ns, int dep)
{
    if (0 == ns)
    {
        if (dep > mx) mx = dep;
        return 1;
    }
    int i, j, k, p, cnt;
    for (i = 0; i < ns; i++)
    {
        k = stk[dep][i];
        cnt = 0;
        if (dep + n - k <= mx) return 0;
        if (dep + dp[k] <= mx) return 0;
        for (j = i + 1; j < ns; j++)
        {
            p = stk[dep][j];
            if (g[k][p]) stk[dep + 1][cnt++] = p;
        }
        dfs(n, cnt, dep + 1);
    }
    return 1;
}
int clique(int n)
{
    int i, j, ns;
    for (mx = 0, i = n - 1; i >= 0; i--)
    {
// vertex: 0 ~ n-1
        for (ns = 0, j = i + 1; j < n; j++)
            if (g[i][j]) stk[1][ ns++ ] = j;
        dfs(n, ns, 1);
        dp[i] = mx;
    }
    return mx;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    g =   (bool **) new  bool [(long long )200101][(long long )200101];
    stk = (int **)new int [(long long )200101][(long long )200101];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            g[i][j] = true;
            stk[i][j] = 0;
        }
    }
    for(int i=0; i<n; i++)
    {
        cin>>nm[i];
    }
    st();
    int ans = clique(n);
    cout<<ans<<endl;
    return 0;
}
