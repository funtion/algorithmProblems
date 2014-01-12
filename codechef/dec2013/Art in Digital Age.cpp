#include<iostream>
#include<vector>
using namespace std;
int mp[2000][2000];
int n;
struct ans
{
    int a,b,c,d,color;
    ans(int aa,int bb,int cc,int dd,int clr):a(aa),b(bb),c(cc),d(dd),color(clr) {}
    ans() {}

};
ostream& operator<<(ostream& o,const ans& a){
    return o<<a.color<<' '<<a.a+1<<' '<<a.c+1<<' '<<a.b+1<<' '<<a.d+1;
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>mp[i][j];
        }
    }
    vector<ans> v1,v2;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n;)
        {
            int k = j;
            if(mp[i][j] != 0)
            {

                for(k=j; k<n; k++)
                {
                    if(mp[i][k+1]!=mp[i][j])
                        break;
                }

                v1.push_back(ans(i,j,i,k,mp[i][j]));
            }
            j = k+1;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n;)
        {
            int k = j;
            if(mp[j][i] != 0)
            {

                for(k=j; k<n; k++)
                {
                    if(mp[k+1][i]!=mp[j][i])
                        break;
                }

                v2.push_back(ans(j,i,k,i,mp[j][i]));
            }
            j = k+1;
        }
    }
    vector<ans> & va = v1.size()<v2.size()?v1:v2;
    int sz = va.size();
    //cout<<v1.size()<<' '<<v2.size()<<endl;
    cout<<va.size()<<endl;
    for(int i=0;i<sz;i++){
        cout<<va[i]<<endl;
    }

    return 0;
}
