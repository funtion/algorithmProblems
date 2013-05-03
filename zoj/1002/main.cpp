#include <iostream>
#include <stack>
#include<cstring>
using namespace std;
bool m[100][100],mm[100][100];
int able;
int n;
unsigned int ma;
stack<int> ss;
void deep(unsigned int nn)
{
    if(able == 0)
    {
        if(nn> ma)
        {
            ma = nn;
        }
        return ;
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(m[i][j] && mm[i][j])
                {
                    able -- ;
                    int t=0,p=i;
                    mm[i][j] = false;
                    while(--p>=0 && m[p][j])
                    {
                        if(mm[p][j] != false)
                        {
                            mm[p][j] = false;
                            t++;
                            ss.push(p);
                            ss.push(j);
                            able--;
                        }

                    }
                    p=i;
                    while(++p<n && m[p][j])
                    {
                        if(mm[p][j] != false)
                        {
                            mm[p][j] = false;
                            t++;
                            ss.push(p);
                            ss.push(j);
                            able--;
                        }

                    }
                    p = j;
                    while(--p>=0 && m[i][p])
                    {
                        if(mm[i][p] != false)
                        {
                            mm[i][p] = false;
                            t++;
                            ss.push(i);
                            ss.push(p);
                            able--;
                        }

                    }
                    p=j;
                    while(++p<n && m[i][p])
                    {
                        if(mm[i][p] != false)
                        {
                            mm[i][p] = false;
                            t++;
                            ss.push(i);
                            ss.push(p);
                            able--;
                        }

                    }
                    deep(nn+1);
                    able+=t;
                    able++;
                    mm[i][j] = true;
                    while(t--)
                    {
                        int tt= ss.top();
                        ss.pop();
                        int ttt=ss.top();
                        ss.pop();
                        mm[ttt][tt] = true;
                    }
                }
            }
        }
    }
}
int main()
{
    char t;
    while(cin>>n,n!=0)
    {
        able= n*n;
        ma = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>t;
                if(t=='X')
                {
                    m[i][j] = false;
                    able--;
                }
                else
                {
                    m[i][j] = true;
                }
            }

        }
        memset(mm,true,sizeof(mm));
        deep(0);
        cout<<ma<<endl;
    }

    return 0;
}
