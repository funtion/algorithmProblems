#include<iostream>
#include<algorithm>
#include<vector>
struct xx{
int num;
int cost;
bool operator<(const xx& r)const{
    if(cost == r.cost)
        return num>r.num;
    return cost < r.cost;
}
}in[11];
using namespace std;

int main()
{
    int v;
    vector<int> ans;
    cin>>v;
    bool ok = false;
    for(int i=1;i<=9;i++)
    {
        cin>>in[i].cost;
        in[i].num = i;
        if(in[i].cost<=v)
            ok = true;
    }
    if(!ok)
    {
        cout<<"-1\n";
        return 0;
    }
    sort(in+1,in+10);
    //for(int i=1;i<=9;i++)
    //    cout<<in[i].num<<':'<<in[i].cost<<endl;
    /*
    for(int i=1;i<=9;i++)
    {
        int a = v/in[i].cost;
        for(int j=0;j<a;j++)
            ans.push_back(in[i].num);//cout<<in[i].num;
        v-=a*in[i].cost;
    }
    sort(ans.begin(),ans.end(),greater<int>());
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i];
    }
    */
    int a = v/in[1].cost;
    for(int i=0;i<a;i++)
        cout<<in[1].num;
    return 0;
}
