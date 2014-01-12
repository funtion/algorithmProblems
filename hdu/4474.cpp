#include <iostream>
#include<cstring>
#include <queue>
#include <string>
using namespace std;
bool x[11];
int vis[100010];
int ct,can[11];
struct st{
    string ans;
    int value;
    st(string s,int v):ans(s),value(v){}
    st(char s,int v):ans(""),value(v){
        ans+=s;
    }
    st():ans(""),value(0){
    }
};
string res;
int cs=0,n,m,y;
bool bfs()
{
    queue<st> qu;
    for(int i=1;i<10;i++)
    {
        if(x[i])
            continue;
        if(i%n==0){
             res = string("")+char('0'+i);
             return true;
        }

        qu.push(st('0'+i,i%n));//cout<<"x"<<i<<' '<<n<<' '<<i%n<<endl;
        vis[i%n] = true;
    }
    while(!qu.empty()){
        st temp = qu.front();
        qu.pop();
        //cout<<temp.ans<<' '<<temp.value<<endl;
        for(int i=0;i<10;i++)
        {
            if(x[i])
                continue;
            if( (temp.value)%n == 0){
                res  = temp.ans;
                return true;
            }else if(vis[(temp.value*10+i)%n])
                continue;
            else{
                vis[(temp.value*10+i)%n] = true;
                qu.push(st(temp.ans+char('0'+i),(temp.value*10+i)%n));
            }
        }
    }
    return false;
}
int main(){


    while(cin>>n&&n){
        cin>>m;
        memset(x,0,sizeof(x));
        memset(vis,false,sizeof(vis));
        ct = 0;
        for(int i=0;i<m;i++){
            cin>>y;
            x[y] = true;
        }
        /*
        for(int i=0;i<=9;i++){
            if( !x[i])
                can[ct++] = i;
        }
        */
        //for(int i=0;i<10;i++)
        //    cout<<x[i]<<endl;

        if(bfs()){
            cout<<"Case "<<++cs<<": "<<res<<endl;
            //printf("Case %d: %s\n",cs++,res.ans.c_str());
        }else{
            cout<<"Case "<<++cs<<": -1"<<endl;
            //printf("Case %d: -1\n",cs++);
        }

    }
}
