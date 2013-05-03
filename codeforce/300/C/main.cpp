#include <iostream>
typedef int T;
using namespace std;
int a,b;
T c;
T cc(T k){
    T result = 1;
    while(k<=c){
        result *=k;
        k++;
    }
}
bool isb(T x){
    while(x!=0){
        if(x%10 != a && x%10 !=b){
            return false;
        }
        x/=10;
    }
    return true;
}
int main()
{
    cin>>a>>b>>c;
    int d = b-a;
    if(d<0){
        d= -d;
        a=b;
    }
    T con=0;
    T in = a*c;
    for(T i=0;i<c;i++){
        if(isb(in)){
            con += cc(i);
        }
        in+=d;
    }
    cout<<con;
    return 0;
}
