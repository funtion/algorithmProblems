#include <iostream>
#include <fstream>
#include <cstring>
#include <set>
#define maxn 50002
long long A[maxn];
using namespace std;
set<long long> ss;
ifstream in;
long long f(long long x){
    while(x!=A[x])
        x =A[x];
    return x;
}
bool  go()
{
    long long n,m;
    cin>>n>>m;
    if(n== 0 && m==0){
        return false;
    }
    ss.clear();
    for( long long i=0;i<maxn;i++){
        A[i] = i;
    }

    long long a,b,fa,fb;
    for(long long i=0;i<m;i++){
        cin>>a>>b;
        fa = f(a);
        fb = f(b);
        A[fb] = fa;
    }
    for(long long i=1;i<n+1;i++){
        A[i] = f(i);
    }
    for(long long i=1;i<n+1;i++){
        ss.insert(f(A[i]));
    }
    long long sum = ss.size();
    cout<<sum;
    return true;
}

int main(){
   // in.open("in.txt");
    while(go())
        cout<<endl;
    return 0;
}
