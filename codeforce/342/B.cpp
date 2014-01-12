#include<iostream>
using namespace std;
typedef long long ll;
ll l[100010],r[100010];
int main(){
    ios::sync_with_stdio(false);
    ll n,m,s,f,t,x,y;
    cin>>n>>m>>s>>f;
    for(ll i=0;i<m;i++){
        cin>>t>>x>>y;
        l[t] = x;
        r[t] = y;
    }
    ll pos = s,stp = 1;
    char c;
    if(f>s){t=1;c='R';}
    else {t = -1;c='L';}
    while(pos!=f){
        if( (l[stp]<=pos&&r[stp]>=pos)||(l[stp]<=pos+t&&r[stp]>=pos+t)){
            cout<<'X';
        }else{
            pos+=t;
            cout<<c;
        }
        stp++;
    }

}
