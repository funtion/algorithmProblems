#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

vector<long long> a,b,mx,sum;
int main()
{
    char cmd;
    int x;
    int q;
    freopen("4699.in","r",stdin);
    freopen("46699.out","w",stdout);
    while(scanf("%d",&q)==1)
    {
        a.clear();
        b.clear();
        mx.clear();
        sum.clear();
        for(int i=0; i<q; i++)
        {
            scanf("%s",&cmd);//puts("xx");//cin>>cmd;
            if(cmd=='I')
            {

                scanf("%d",&x);//cin>>x;
                a.push_back(x);
                if(sum.empty())
                {
                    sum.push_back(x);
                    mx.push_back(x);
                }
                else
                {
                    sum.push_back(sum.back()+x);
                    long long mm = mx.back();
                    mx.push_back(max(mm,sum.back()));
                }

            }
            else if(cmd == 'D')
            {
                if(!a.empty())
                {
                    a.pop_back();
                    mx.pop_back();
                    sum.pop_back();
                }
            }
            else if(cmd == 'L')
            {
                if(!a.empty())
                {
                    long long mm = a.back();
                    a.pop_back();
                    mx.pop_back();
                    sum.pop_back();
                    b.push_back(mm);
                }
            }
            else if(cmd=='R')
            {
                if(!b.empty())
                {
                    long long mm = b.back();
                    b.pop_back();
                    if(a.empty())
                    {
                        a.push_back(mm);
                        sum.push_back(mm);
                        mx.push_back(mm);
                    }
                    else
                    {
                        a.push_back(mm);
                        sum.push_back(mm+sum.back());
                        long long xx = mx.back();
                        mx.push_back(max(xx,sum.back()));
                    }
                }

            }
            else  //cmd =='Q'
            {
                scanf("%d",&x);//cin>>x;
                long long xx = mx[x-1];
                printf("%I64d\n",xx);//cout<<xx<<endl;
            }
        }

    }
}
