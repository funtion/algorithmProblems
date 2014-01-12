#include <iostream>
#include <vector>
using namespace std;
int n,m;
int F[50];
inline int f(int x){
    if(F[x]==x)
        return x;
    return F[x] = f(F[x]);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        F[i] = i;
    int a,b,fa,fb;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        fa = f(a);
        fb = f(b);
        F[fa] = fb;
    }
    vector<int> vi[50];
    for(int i=1;i<=n;i++){
        vi[f(i)].push_back(i);
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(vi[i].size())
            cnt++;
    }
    if(cnt<3){
        cout<<"-1\n";
    }else{

    }
}
