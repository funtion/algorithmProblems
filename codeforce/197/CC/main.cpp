#include<iostream>
using namespace std;
int n,cnt;
bool it[11];
int ans[1010],sl,sr;
bool  dfs(int m,int x)
{
    if(m==n)
    {
        ans[n] = x;
        return true;
    }
    else
    {
        for(int i=1; i<=10; i++)
        {
            if(it[i]&&x!=i)
            {
                if(m%2==0&&sl+i>sr)
                {
                    sl+=i;
                    if(dfs(m+1,i))
                    {
                        ans[m] = i;
                        return true;
                    }
                    sl-=i;
                }
                else if(m%2==1&&sr+i>sl)
                {
                    sr+=i;
                    if(dfs(m+1,i))
                    {
                        ans[m] = i;
                        return true;
                    }
                    sr-=i;
                }
            }
        }
        return false;
    }
}
int main()
{
    char x;
    for(int i=1; i<=10; i++)
    {
        cin>>x;
        if(x=='1')
        {
            it[i] = true;
            cnt++;
        }
    }
    cin>>n;
    if(cnt==1)
    {
        if(n>1)
            cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            for(int i=1; i<=10; i++)
            {
                if(it[i])
                {
                    cout<<i;
                    break;
                }
            }
        }
    }
    else
    {
        bool tg = false;
        for(int i=1; i<=10; i++)
        {
            if(it[i])
            {
                sl+=i;
                if(dfs(1,i))
                {
                    ans[0] = i;
                    tg = true;
                    break;
                }
                sl-=i;
            }

        }
        if(!tg)
        {
            cout<<"NO\n";
        }
        else
        {
            cout<<"YES\n";
            for(int i=0; i<n; i++)
            {
                cout<<ans[i]<<' ';
            }
        }
    }

}
