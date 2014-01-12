#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int n,m,x,k;
struct st
{
    ll s[3][3];
    ll s1,s2;
    int begin,end;
}ss[60];
ll fib[50];
vector<ll> vec;
bool di(){
    ll tmp = x;
    for(int i=0;i<3;i++){
        for(int j=49;j>=0;j--){
            if(fib[j]<=tmp){
                vec.push_back(fib[j]);
                tmp-=fib[j];
                if(tmp==0)
                    return true;
                break;
            }
        }
    }
    return false;
}
int main(){
    fib[0]=fib[1] = 1;
    for(int i=2;i<50;i++){
        fib[i] = fib[i-1]+fib[i-2];
        //cout<<fib[i]<<endl;
    }
    cin>>k>>x>>n>>m;
    //cin>>x;
    //bool ff = di();
    /*
    cout<<ff<<endl;
    for(int i=0;i<vec.size();i++){
        
        cout<<vec[i]<<' ';
    }
    
    if(!ff){
        cout<<"Happy new year!\n";
        return 0;
    }*/
    ss[1].s1 = 1;
    ss[1].begin = ss[1].end = 1;
    ss[2].s2 = 1;
    ss[2].begin = ss[2].end = 2;
    for(int i=3;i<=k;i++){
        ss[i].s1 = ss[i-1].s1+ss[i-2].s1;
        ss[i].s2 = ss[i-1].s2+ss[i-2].s2;
        ss[i].s[1][2] = ss[i-1].s[1][2]+ss[i-2].s[1][2];
        ss[i].s[2][1] = ss[i-1].s[2][1]+ss[i-2].s[2][1];
        ss[i].s[1][1] = ss[i-1].s[1][1]+ss[i-2].s[1][1];
        ss[i].s[2][2] = ss[i-1].s[2][2]+ss[i-2].s[2][2];
        ss[i].begin = ss[i-2].begin;
        ss[i].end = ss[i-1].end;
        if(ss[i-2].end == 1){
            if(ss[i-1].begin == 1){
                ss[i].s[1][1]++;
            }else{
                ss[i].s[1][2]++;
            }
        }else{
            if(ss[i-1].begin == 1){
                ss[i].s[2][1]++;
            }else{
                ss[i].s[2][2]++;
            }
        }
    }
    /*
    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++){
            cout<<ss[k].s[i][j]<< ' ';
        }
        cout<<endl;
    }*/
    if(x <= ss[k].s1*(n/2)+ss[k].s2*(m/2)){
        ll cnt = 0;
        for(int i=0;i<n;i++){
            
            if(cnt>=x*2)
                cout<<"A";
            
            else
                cout<<(i%2==0?'A':'C');
            cnt++;
            //cout<<cnt;
        }
        cout<<endl;
        for(int i=0;i<m;i++){
            
            if(cnt>=x*2)
                cout<<"A";
            
            else
                cout<<(i%2==0?'A':'C');
            cnt++;
        }
        cout<<endl;
    }else{
        cout<<"Happy new year!\n";
    }


    return 0;
}