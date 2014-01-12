#include<iostream>
#include<cstring>
using namespace std;
#define M 100000001
typedef long long ll;
bool a[M];
int main(){
    memset(a,1,sizeof(a));
    a[1] = false;
    for(ll i=2;i<M;i++){
        if(a[i]){//cout<<i<<endl;
            for(ll j=i*i;j<M;j+=i)
                a[j] = false;
        }
    }

    int n;
    while(cin>>n){
        int s = 0;
        for(int i=1;i<=n;i++){
            if(a[i])
                s++;
        }
        cout<<s<<endl;
    }
}
