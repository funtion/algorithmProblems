#define cin in
#define cout out
#include <fstream>

#include <iostream>
#include <cstring>
#include <climits>
#include <vector>


using namespace std;
int N,T;
vector<int> ma [120];
int isVisited[120];
int cost[120][120];
bool rt[120][120];
int va[120];
int a,b,t;
long long mx =0;
void dfs(int location,int time,int value){
    if(!isVisited[location])
        value+=va[location];
    isVisited[location ] ++;
    if(location == N && value > mx){
        mx = value;

    }
    for(vector<int>::iterator i = ma[location].begin();i!=ma[location].end();i++){
        if(time - cost[location][*i]>=0 && !rt[location][*i]){//> or >=
            rt[location][*i] = true;
            dfs(*i,time - cost[location][*i],value);
            rt[location][*i] = false;
        }
    }
    isVisited[location] --;
}
int main()
{
    //ifstream in("in.txt");
    //ofstream out("out.txt");
    while(cin>>N>>T){
        memset(ma,0,sizeof(ma));
        memset(cost,0,sizeof(cost));
        memset(isVisited,0,sizeof(isVisited));
        memset(rt,false,sizeof(rt));
         for(int i=1;i<N;i++){
        cin>>a>>b>>t;
        cost[a][b] = t;
        cost[b][a] = t;
        ma[a].push_back(b);
        ma[b].push_back(a);
    }
    for(int i=1;i<=N;i++)
        cin>>va[i];

    mx=0;
    dfs(1,T,0);
    if(mx>0)
        cout<<mx<<endl;
    else
        cout<<"Human beings die in pursuit of wealth, and birds die in pursuit of food!\n";
    }

    return 0;
}
