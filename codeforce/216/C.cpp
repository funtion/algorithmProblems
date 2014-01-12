#include<iostream>
#include<vector>
using namespace std;
int n;
struct node{
    int a,b;
//    int son;
    int type;
};
vector<node> tree[300000];
bool need[300000];
vector<int> an;
void dw(int x,int pre)
{
    int sz = tree[x].size();
    if(x!=1 &&sz == 1)
    {
        //cout<<tree[x][0].type<<endl;
        if(tree[x][0].type == 2)
        {

            an.push_back(x);
            need[x] = true;
            //ans++;
        }
        return ;
    }
    bool d = false;
    for(int i=0;i<sz;i++)
    {
        node tp = tree[x][i];
        if(tp.b != pre)
        {
            dw(tp.b,x);
            if(need[tp.b])
                need[x] = true;
        }
        else
        {
            if(tp.type == 2)
                d = true;
        }
    }
    if(!need[x] && d)
    {
        //ans++;
        an.push_back(x);
        need[x] = true;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    int a,b,c;
    node temp;
    for(int i=1;i<n;i++){
        cin>>a>>b>>c;
        temp.a = a;
        temp.b = b;
        temp.type = c;
        tree[a].push_back(temp);
        temp.a = b;
        temp.b = a;
        tree[b].push_back(temp);
    }
    dw(1,-1);
    int ans = an.size();
    cout<<ans<<endl;
    for(int i=0;i<ans;i++)
        cout<<an[i]<<' ';
    return 0;
}
