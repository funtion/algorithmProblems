#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;
int main()
{
    freopen("in.txt","w",stdout);
    srand(time(0));
    cout<<1000<<endl;
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            long long t = rand()+1;
            t*=rand()+1;
            t%=1000000000LL;
            cout<<t<<' ';
        }
        cout<<endl;
    }
}
